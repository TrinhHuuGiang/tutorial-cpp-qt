- [Documentation](https://doc.qt.io/qt-6.5/qvariant.html)
- Perpose: QVariant is a Qt class that can store different types of data in a single variable. It is useful for handling dynamic data, converting between types, and storing values in models, settings, or inter-process communication.

# QVariant Methods Classification

| Category            | Methods |
|---------------------|---------|
| **Constructor/Destructor** | `~QVariant` |
| **Conversion Methods** | `canConvert`, `convert`, `canView` |
| **Value and Type Methods** | `clear`, `data`, `isNull`, `isValid`, `metaType`, `setValue`, `swap`, `typeId`, `typeName`, `userType`, `value` |
| **View Methods** | `view`, `constData` |
| **Utility Methods** | `swap`, `setValue` |
| **Numeric Conversions** | `toBool`, `toDouble`, `toFloat`, `toInt`, `toLongLong`, `toReal`, `toUInt`, `toULongLong` |
| **String and Byte Conversions** | `toString`, `toStringList`, `toByteArray` |
| **Date and Time Conversions** | `toDate`, `toDateTime`, `toTime` |
| **Geometry Conversions** | `toPoint`, `toPointF`, `toRect`, `toRectF`, `toSize`, `toSizeF`, `toLine`, `toLineF` |
| **Collection Conversions** | `toList`, `toMap`, `toHash` |
| **JSON Conversions** | `toJsonArray`, `toJsonDocument`, `toJsonObject`, `toJsonValue` |
| **Miscellaneous Conversions** | `toChar`, `toUrl`, `toUuid`, `toRegularExpression`, `toBitArray`, `toEasingCurve`, `toLocale` |
| **Model Index Conversions** | `toModelIndex`, `toPersistentModelIndex` |
| **Operators** | `operator=` |
