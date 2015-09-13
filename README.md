

## 注意

1. linux 识别不了`atoi`函数，改用`istringstream`进行格式转换，见[150-evaluate-reverse-polish-notation.cpp](src/problems/150-evaluate-reverse-polish-notation.cpp)

2. `memset(ptr, INT_MAX/INT_MIN, sizeof(ptr))`会导致错误，memset只复制低8位字节

3. 64位int：添加头文件`inttypes.h`, 使用`uint64\_t` or `int64\_t`, 见[166-fraction-to-recurring-decimal.cpp]

4. `sort(a.begin(), a.end(), compare_fir>sec)`是降序排列, 而 `qsort(p, p_count, p_struct_size, compare_fir-sec` 是升序排列,见[src/test/srt_qsort.cpp](src/test/srt_qsort.cpp)