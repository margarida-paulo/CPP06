**Static_cast**

Performs compile time checks. It's the most appropriate for converting built-in types into each other.
For example, int to float, float to double, etc.
With the compile time checks, the compiler will let us know if we try to convert datatypes that shouldn't be converted.

**Reinterpret_cast**

Doesn't perform any kind of checks. It's ideal to convert completely unrelated types into each other, because it simply
interprets the bit pattern of one object as if it were another type, without changing anything about it or doing any verifications,