- [Documentation](https://doc.qt.io/qt-6.5/qstring.html#Iterator-typedef)
- Perpose: QString is a string class that makes it easy to work with text, supports `Unicode`, provides useful functions for searching and modifying text, and manages memory efficiently.
<hr>

| **Constructor / Destructor** | **String Operations** | **Query / Check** | **Conversion** | **Operators** |
|-----------------------------|----------------------|------------------|---------------|-------------|
| `QString()`                 | `append`            | `at`             | `toCFString`  | `operator!=` |
| `~QString()`                | `chop`              | `back()`         | `toCaseFolded` | `operator+=` |
|                             | `chopped`           | `begin`          | `toDouble`    | `operator<`  |
| **Memory / Capacity**       | `clear`             | `cbegin`         | `toFloat`     | `operator<=` |
| `capacity`                  | `erase`             | `cend`           | `toHtmlEscaped` | `operator=`  |
| `reserve`                   | `fill`              | `constBegin`     | `toInt`       | `operator==` |
| `resize`                    | `insert`            | `constData`      | `toLatin1`    | `operator>`  |
| `shrink_to_fit`             | `prepend`           | `constEnd`       | `toLocal8Bit` | `operator>=` |
| `size`                      | `push_back`         | `contains`       | `toLong`      | `operator[]` |
|                             | `push_front`        | `count`          | `toLongLong`  |              |
| **String Splitting / Trimming** | `remove`        | `crbegin`        | `toLower`     | **Unicode / Encoding** |
| `left`                      | `removeAt`          | `crend`          | `toNSString`  | `unicode`    |
| `leftJustified`             | `removeFirst`       | `data`           | `toShort`     | `utf16`      |
| `mid`                       | `removeIf`          | `end`            | `toStdString` |              |
| `normalized`                | `removeLast`        | `endsWith`       | `toStdU16String` |           |
| `repeated`                  | `replace`           | `first`          | `toStdU32String` |           |
| `right`                     | `simplified`        | `front`          | `toStdWString` |             |
| `rightJustified`            | `tokenize`          | `indexOf`        | `toUInt`      |              |
| `section`                   | `trimmed`           | `isEmpty`        | `toULong`     |              |
| `sliced`                    | `truncate`          | `isLower`        | `toULongLong` |              |
| `split`                     |                     | `isNull`         | `toUShort`    |              |
| `startsWith`                | **Iteration**       | `isRightToLeft`  | `toUcs4`      |              |
|                             | `rbegin`            | `isUpper`        | `toUpper`     |              |
| **Comparison**              | `rend`              | `isValidUtf16`   | `toUtf8`      |              |
| `compare`                   |                     | `last`           | `toWCharArray` |             |
| `localeAwareCompare`        | **Data Setting**    | `lastIndexOf`    | **Immutable Functions** |    |
|                             | `setNum`            | `length`         | `chopped`     |              |
|                             | `setRawData`        | `localeAwareCompare` | `sliced`  |              |
|                             | `setUnicode`        | `mid`            |               |              |
|                             | `setUtf16`          |                  |               |              |
