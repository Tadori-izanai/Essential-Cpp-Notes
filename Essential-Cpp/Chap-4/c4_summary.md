## Chapater 4









### 补充

- 枚举

    ```cpp
    enum color {red, yellow, green};			// 不限定作用域的枚举类型
    enum class peppers {red, yellow, green};
    // 定义
    color eyes = green;			// 对
    color hair = color::red;	// 对, 允许显式访问枚举成员
    peppers p = pappers::green;	// 对
    ```

    