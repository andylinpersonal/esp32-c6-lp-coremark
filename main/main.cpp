/**
 * See https://github.com/espressif/idf-extra-components/blob/master/coremark/examples/coremark_example
 * Some modifications to ESP-IDF may be needed.
 *
 * 1. Replace "-Os" with "-O3 -fjump-tables -ftree-switch-conversion" in
 * $IDF_PATH/components/ulp/cmake/toolchain-lp-core-riscv.cmake
 * 2. Add the following include paths to $IDF_PATH/components/ulp/cmake/CMakeLists.txt
 *   ```
 *     target_sources(${ULP_APP_NAME} PRIVATE ${ULP_S_SOURCES})
 *     target_include_directories(${ULP_APP_NAME} PRIVATE "${IDF_PATH}/components/ulp/lp_core/lp_core/include"
 *                                                        "${IDF_PATH}/components/ulp/lp_core/shared/include"
 *                                                        <ADD PATHS TO HERE>)
 *     target_compile_definitions(${ULP_APP_NAME} PRIVATE IS_ULP_COCPU)
 *   ```
 *   1. Absolute path to the directory of coremark.h
 *   2. Absolute path to the directory of core_portme.h
 */

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <riscv/rv_utils.h>
#include <soc/clint_reg.h>
#include <soc/lpperi_struct.h>
#include <ulp_lp_core.h>

#include <lp_coremark.h>

#include <atomic>
#include <cmath>
#include <cstdio>

static constexpr char TAG[] = "test";

extern const uint8_t ulp_main_bin_start[] asm("_binary_lp_coremark_bin_start");
extern const uint8_t ulp_main_bin_end[] asm("_binary_lp_coremark_bin_end");

extern volatile uint32_t lp_coremark_ticks asm("ulp_lp_coremark_ticks");
extern volatile uint32_t lp_coremark_iterations asm("ulp_lp_coremark_iterations");
extern volatile uint32_t lp_coremark_done asm("ulp_lp_coremark_done");

static void load_ulp()
{
	esp_err_t err = ulp_lp_core_load_binary(ulp_main_bin_start, (ulp_main_bin_end - ulp_main_bin_start));
	ESP_ERROR_CHECK(err);

	/* Start the program */
	ulp_lp_core_cfg_t cfg = {
	    .wakeup_source = ULP_LP_CORE_WAKEUP_SOURCE_LP_TIMER,
	    .lp_timer_sleep_duration_us = 10000,
	};

	err = ulp_lp_core_run(&cfg);
	ESP_ERROR_CHECK(err);
}

extern "C" void app_main(void)
{
	load_ulp();

	while (true) {
		if (lp_coremark_done) {
			ESP_LOGI(TAG, "LP Core Coremark ticks: %u", (unsigned)lp_coremark_ticks);
			ESP_LOGI(TAG, "LP Core Coremark/MHz: %f", 1000000 * lp_coremark_iterations / (float)lp_coremark_ticks);
		} else {
			ESP_LOGI(TAG, "LP Core coremark is running");
		}
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
