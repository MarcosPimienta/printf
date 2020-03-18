# A printf / sprintf Implementation for Embedded Systems

[![Build Status](https://travis-ci.org/mpaland/printf.svg?branch=master)](https://travis-ci.org/mpaland/printf)
[![codecov](https://codecov.io/gh/mpaland/printf/branch/master/graph/badge.svg)](https://codecov.io/gh/mpaland/printf)
[![Coverity Status](https://img.shields.io/coverity/scan/14180.svg)](https://scan.coverity.com/projects/mpaland-printf)
[![Github Issues](https://img.shields.io/github/issues/mpaland/printf.svg)](http://github.com/mpaland/printf/issues)
[![Github Releases](https://img.shields.io/github/release/mpaland/printf.svg)](https://github.com/mpaland/printf/releases)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/mpaland/avl_array/master/LICENSE)

This is a tiny but **fully loaded** printf, sprintf and (v)snprintf implementation.
Primarily designed for usage in embedded systems, where printf is not available due to memory issues or in avoidance of linking against libc.
Using the standard libc printf may pull **a lot** of unwanted library stuff and can bloat code size about 20k or is not 100% thread safe. In this cases the following implementation can be used.
Absolutely **NO dependencies** are required, *printf.c* brings all necessary routines, even its own fast `ftoa` (floating point), `ntoa` (decimal) conversion.

If memory footprint is really a critical issue, floating point, exponential and 'long long' support and can be turned off via the `PRINTF_DISABLE_SUPPORT_FLOAT`, `PRINTF_DISABLE_SUPPORT_EXPONENTIAL` and `PRINTF_DISABLE_SUPPORT_LONG_LONG` compiler switches.
When using printf (instead of sprintf/snprintf) you have to provide your own `_putchar()` low level function as console/serial output.


## 2020 announcement
This project is not dead! I just had no time in 2019 for sufficient support, sorry.
Within the next weeks, I will have a look to all PRs and open issues.  
Thank you all for supporting this project.


## Highlights and Design Goals

There is a boatload of so called 'tiny' printf implementations around. So why this one?
I've tested many implementations, but most of them have very limited flag/specifier support, a lot of other dependencies or are just not standard compliant and failing most of the test suite.
Therefore I decided to write an own, final implementation which meets the following items:

 - Very small implementation (around 600 code lines)
 - NO dependencies, no libs, just one module file
 - Support of all important flags, width and precision sub-specifiers (see below)
 - Support of decimal/floating number representation (with an own fast itoa/ftoa)
 - Reentrant and thread-safe, malloc free, no static vars/buffers
 - LINT and compiler L4 warning free, mature, coverity clean, automotive ready
 - Extensive test suite (> 400 test cases) passing
 - Simply the best *printf* around the net
 - MIT license


## Usage

Add/link *printf.c* to your project and include *printf.h*. That's it.
Implement your low level output function needed for `printf()`:
```C
void _putchar(char character)
{
  // send char to console etc.
}
Usage is 1:1 like the according stdio.h library version:
C
int printf(const char* format, ...);
int sprintf(char* buffer, const char* format, ...);
int snprintf(char* buffer, size_t count, const char* format, ...);
int vsnprintf(char* buffer, size_t count, const char* format, va_list va);

// use output function (instead of buffer) for streamlike interface
int fctprintf(void (*out)(char character, void* arg), void* arg, const char* format, ...);
**Due to general security reasons it is highly recommended to prefer and use snprintf (with the max buffer size as count parameter) instead of sprintf.**
sprintf has no buffer limitation, so when needed - use it really with care!
### Streamlike Usage
Besides the regular standard printf() functions, this module also provides fctprintf(), which takes an output function as first parameter to build a streamlike output like fprintf():
C
// define the output function
void my_stream_output(char character, void* arg)
{
  // opt. evaluate the argument and send the char somewhere
}

{
  // in your code
  void* arg = (void*)100;  // this argument is passed to the output function
  fctprintf(&my_stream_output, arg, "This is a test: %X", 0xAA);
  fctprintf(&my_stream_output, nullptr, "Send to null dev");
}# A printf / sprintf Implementation for Embedded Systems

[![Build Status](https://travis-ci.org/mpaland/printf.svg?branch=master)](https://travis-ci.org/mpaland/printf)
[![codecov](https://codecov.io/gh/mpaland/printf/branch/master/graph/badge.svg)](https://codecov.io/gh/mpaland/printf)
[![Coverity Status](https://img.shields.io/coverity/scan/14180.svg)](https://scan.coverity.com/projects/mpaland-printf)
[![Github Issues](https://img.shields.io/github/issues/mpaland/printf.svg)](http://github.com/mpaland/printf/issues)
[![Github Releases](https://img.shields.io/github/release/mpaland/printf.svg)](https://github.com/mpaland/printf/releases)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/mpaland/avl_array/master/LICENSE)

This is a tiny but **fully loaded** printf, sprintf and (v)snprintf implementation.
Primarily designed for usage in embedded systems, where printf is not available due to memory issues or in avoidance of linking against libc.
Using the standard libc printf may pull **a lot** of unwanted library stuff and can bloat code size about 20k or is not 100% thread safe. In this cases the following implementation can be used.
Absolutely **NO dependencies** are required, *printf.c* brings all necessary routines, even its own fast `ftoa` (floating point), `ntoa` (decimal) conversion.

If memory footprint is really a critical issue, floating point, exponential and 'long long' support and can be turned off via the `PRINTF_DISABLE_SUPPORT_FLOAT`, `PRINTF_DISABLE_SUPPORT_EXPONENTIAL` and `PRINTF_DISABLE_SUPPORT_LONG_LONG` compiler switches.
When using printf (instead of sprintf/snprintf) you have to provide your own `_putchar()` low level function as console/serial output.


## 2020 announcement
This project is not dead! I just had no time in 2019 for sufficient support, sorry.
Within the next weeks, I will have a look to all PRs and open issues.  
Thank you all for supporting this project.


## Highlights and Design Goals

There is a boatload of so called 'tiny' printf implementations around. So why this one?
I've tested many implementations, but most of them have very limited flag/specifier support, a lot of other dependencies or are just not standard compliant and failing most of the test suite.
Therefore I decided to write an own, final implementation which meets the following items:

 - Very small implementation (around 600 code lines)
 - NO dependencies, no libs, just one module file
 - Support of all important flags, width and precision sub-specifiers (see below)
 - Support of decimal/floating number representation (with an own fast itoa/ftoa)
 - Reentrant and thread-safe, malloc free, no static vars/buffers
 - LINT and compiler L4 warning free, mature, coverity clean, automotive ready
 - Extensive test suite (> 400 test cases) passing
 - Simply the best *printf* around the net
 - MIT license


## Usage

Add/link *printf.c* to your project and include *printf.h*. That's it.
Implement your low level output function needed for `printf()`:
```C
void _putchar(char character)
{
  // send char to console etc.
}
Usage is 1:1 like the according stdio.h library version:
C
int printf(const char* format, ...);
int sprintf(char* buffer, const char* format, ...);
int snprintf(char* buffer, size_t count, const char* format, ...);
int vsnprintf(char* buffer, size_t count, const char* format, va_list va);

// use output function (instead of buffer) for streamlike interface
int fctprintf(void (*out)(char character, void* arg), void* arg, const char* format, ...);
**Due to general security reasons it is highly recommended to prefer and use snprintf (with the max buffer size as count parameter) instead of sprintf.**
sprintf has no buffer limitation, so when needed - use it really with care!
### Streamlike Usage
Besides the regular standard printf() functions, this module also provides fctprintf(), which takes an output function as first parameter to build a streamlike output like fprintf():
C
// define the output function
void my_stream_output(char character, void* arg)
{
  // opt. evaluate the argument and send the char somewhere
}

{
  // in your code
  void* arg = (void*)100;  // this argument is passed to the output function
  fctprintf(&my_stream_output, arg, "This is a test: %X", 0xAA);
  fctprintf(&my_stream_output, nullptr, "Send to null dev");
}
