# Modifications to thirdparty codes

* Coremark
  * Due to space constraints, I cannot place printf onto LP Core. To expose these results to HP core, I modified coremark's main function slightly. Benchmark code are kept intact.
* ESP-IDF
  * Changing compiler flags and include paths are impossible without modification to ESP-IDF currently.

# Platform

* Board:   ESP32-C6-Devkit-C
* Chip:    ESP32-C6 v0.0
* ESP-IDF: Based on master (v5.4) 8760e6d2a7e19913bc40675dd71f374bcd51b0ae

# Results

```
-Os
I (38086) test: LP Core Coremark/MHz: 1.606688
   text    data     bss     dec     hex filename
   7234      24    2040    9298    2452 build/esp-idf/main/lp_coremark/lp_coremark

-Os -msave-restore
I (26086) test: LP Core Coremark/MHz: 1.567058
   text    data     bss     dec     hex filename
   6996      24    2040    9060    2364 build/esp-idf/main/lp_coremark/lp_coremark.elf

-O2
I (28086) test: LP Core Coremark/MHz: 2.039459
   text    data     bss     dec     hex filename
   8356      24    2040   10420    28b4 build/esp-idf/main/lp_coremark/lp_coremark.elf

-O2 -msave-restore
I (34086) test: LP Core Coremark/MHz: 1.995059
   text    data     bss     dec     hex filename
   8122      24    2040   10186    27ca build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3
I (23086) test: LP Core Coremark/MHz: 2.153785
   text    data     bss     dec     hex filename
  10002      24    2040   12066    2f22 build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3 -msave-restore
I (23086) test: LP Core Coremark/MHz: 2.125598
   text    data     bss     dec     hex filename
   9812      24    2040   11876    2e64 build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3 -fno-jump-tables
I (18086) test: LP Core Coremark/MHz: 2.035384
   text    data     bss     dec     hex filename
  10042      24    2040   12106    2f4a build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3 -fno-jump-tables -fno-tree-switch-conversion
I (24086) test: LP Core Coremark/MHz: 2.035384
   text    data     bss     dec     hex filename
  10042      24    2040   12106    2f4a build/esp-idf/main/lp_coremark/lp_coremark.elf

-Ofast
I (54086) test: LP Core Coremark/MHz: 2.153785
   text    data     bss     dec     hex filename
  10002      24    2040   12066    2f22 build/esp-idf/main/lp_coremark/lp_coremark.elf

```
