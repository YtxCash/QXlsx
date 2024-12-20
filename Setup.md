# Setup

## Use without installation in CMakeLists

2 possible ways:

- first

```CMakeLists
add_subdirectory(YXlsx)
target_link_libraries(myapp PRIVATE YXlsx::YXlsx)
```

- second

```CMakeLists
include(FetchContent)

FetchContent_Declare(
  YXlsx
  GIT_REPOSITORY https://github.com/YtxCash/YXlsx.git
  GIT_TAG        sha-of-the-commit
  SOURCE_SUBDIR  YXlsx
)
FetchContent_MakeAvailable(YXlsx)
target_link_libraries(myapp PRIVATE YXlsx::YXlsx)
```
