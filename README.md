

## 注意

1. linux 识别不了`atoi`函数，改用`istringstream`进行格式转换，见[150-evaluate-reverse-polish-notation.cpp](src/problems/150-evaluate-reverse-polish-notation.cpp)

2. `memset(ptr, INT_MAX/INT_MIN, sizeof(ptr))`会导致错误，memset只复制低8位字节

3. 64位int：添加头文件`inttypes.h`, 使用`uint64\_t` or `int64\_t`, 见[166-fraction-to-recurring-decimal.cpp]

4. `sort(a.begin(), a.end(), compare_fir>sec)`是降序排列, 而 `qsort(p, p_count, p_struct_size, compare_fir-sec` 是升序排列,见[src/test/srt_qsort.cpp](src/test/srt_qsort.cpp)

5. `runtime error`可能是数组访问越界,除0，爆栈,很小可能能是内存不够

6. `map`一定要find找到后再map[i]. 如果不存在且直接用map[i]会报错

7. `220-contains-duplicate-iii.cpp` 虽然过了,但是特别慢

8.`222-count-complete-tree-nodes.cpp`看了答案