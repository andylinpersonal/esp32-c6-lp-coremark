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
I (26084) test: LP Core Coremark/MHz: 1.577193
   text    data     bss     dec     hex filename
   8358       8    2040   10406    28a6 build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3
I (22085) test: LP Core Coremark/MHz: 2.160275
   text    data     bss     dec     hex filename
  11142       8    2040   13190    3386 build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3 -fno-jump-tables
I (22085) test: LP Core Coremark/MHz: 2.027998
   text    data     bss     dec     hex filename
  11182       8    2040   13230    33ae build/esp-idf/main/lp_coremark/lp_coremark.elf

-O3 -fno-jump-tables -fno-tree-switch-conversion
I (22085) test: LP Core Coremark/MHz: 2.027998
   text    data     bss     dec     hex filename
  11182       8    2040   13230    33ae build/esp-idf/main/lp_coremark/lp_coremark.elf

-Ofast
I (26085) test: LP Core Coremark/MHz: 2.160275
   text    data     bss     dec     hex filename
  11142       8    2040   13190    3386 build/esp-idf/main/lp_coremark/lp_coremark.elf
```
