<!-- :) Don't mind this is just a guide suggested by chatgpt -->
<!-- :) Ignore this folder, it just some note in Qt Documentation -->

## 1. **Cơ Bản về Qt và Ứng Dụng Terminal**
### 1.1. **Hệ thống lõi (QtCore)**
- `QCoreApplication`: [Quản lý vòng lặp sự kiện (event loop)](./_0003_QCoreApplication.md)
- `QString`: [Xử lý chuỗi](./_0004_Qstring.md)
- `QByteArray`: [Quản lý dữ liệu nhị phân](./_0005_QByteArray.md)
- `QVariant`: [Lưu trữ kiểu dữ liệu đa dạng](./_0006_QVariant.md)
- `QDebug`: [Ghi log và debug](./_0007_QDebug.md)

### 1.2. **Xử lý File và Dữ liệu**
- `QFile`: Đọc/ghi file
- `QTextStream`: Làm việc với stream văn bản
- `QDataStream`: Làm việc với stream nhị phân
- `QDir`: Quản lý thư mục
- `QSettings`: Lưu trữ cấu hình ứng dụng

### 1.3. **Lập lịch và Luồng (Threading & Timer)**
- `QTimer`: Hẹn giờ và lập lịch sự kiện
- `QThread`: Quản lý đa luồng
- `QMutex` & `QSemaphore`: Đồng bộ hóa luồng

### 1.4. **Mạng và Giao tiếp (Networking & IPC)**
- `QTcpSocket`, `QTcpServer`: Kết nối mạng TCP
- `QUdpSocket`: Giao tiếp UDP
- `QNetworkAccessManager`: Yêu cầu HTTP
- `QLocalSocket`, `QLocalServer`: Giao tiếp tiến trình nội bộ (IPC)

---

## 2. **Qt Widgets - Lập Trình GUI Cơ Bản**
### 2.1. **Cấu trúc ứng dụng GUI**
- `QApplication`: Quản lý vòng lặp sự kiện cho GUI
- `QWidget`: Cơ sở của mọi widget GUI
- `QMainWindow`: Cửa sổ chính
- `QDialog`: Cửa sổ hộp thoại
- `QLayout`: Quản lý bố cục giao diện

### 2.2. **Các Widget Cơ Bản**
- `QLabel`: Hiển thị văn bản và hình ảnh
- `QPushButton`: Nút bấm
- `QLineEdit`: Ô nhập văn bản
- `QTextEdit`: Soạn thảo văn bản nhiều dòng
- `QCheckBox`, `QRadioButton`: Lựa chọn
- `QComboBox`: Danh sách chọn
- `QListWidget`, `QTreeWidget`, `QTableWidget`: Hiển thị danh sách, bảng

### 2.3. **Xử lý Sự Kiện và Tín Hiệu - Khe (Signal & Slot)**
- Cách kết nối tín hiệu và khe
- Tạo tín hiệu tùy chỉnh
- Xử lý sự kiện bằng `eventFilter`

---

## 3. **Qt nâng cao - Lập Trình Hiện Đại**
### 3.1. **Lập trình giao diện nâng cao**
- `QGraphicsView`: Xây dựng giao diện đồ họa
- `QOpenGLWidget`: Dùng OpenGL trong Qt
- `QML` & `QtQuick`: Tạo UI hiện đại với Qt Quick

### 3.2. **Hệ thống cơ sở dữ liệu (Qt SQL)**
- `QSqlDatabase`: Kết nối CSDL
- `QSqlQuery`: Thực thi truy vấn
- `QSqlTableModel`, `QSqlRelationalTableModel`: Hiển thị dữ liệu

### 3.3. **Đa luồng và Hiệu năng cao**
- `QtConcurrent`: Xử lý bất đồng bộ
- `QFuture`: Kết quả tính toán trong tương lai
- `QThreadPool`: Quản lý nhiều luồng hiệu quả

### 3.4. **Ứng dụng mạng và giao tiếp IPC nâng cao**
- `QWebSocket`: Giao tiếp thời gian thực
- `QNetworkManager`: Tải dữ liệu từ internet
- `QSharedMemory`: Chia sẻ bộ nhớ giữa các tiến trình

### 3.5. **Qt Test - Kiểm thử phần mềm**
- `QTest`: Viết Unit Test
- `QSignalSpy`: Kiểm tra tín hiệu phát ra
- `QBenchmark`: Đo hiệu suất

---

## 4. **Dự án thực tế và tối ưu hóa**
### 4.1. **Xây dựng ứng dụng hoàn chỉnh**
- Ứng dụng Console quản lý dữ liệu
- Ứng dụng GUI quản lý công việc
- Ứng dụng truyền thông mạng (chat, HTTP API…)

### 4.2. **Tối ưu hóa và triển khai**
- `Qt Resource System`: Quản lý tài nguyên
- `Qt Plugin System`: Mở rộng ứng dụng với plugin
- Triển khai ứng dụng Qt trên Windows/Linux/macOS

---
## 🎯 **Hướng dẫn học hiệu quả**
1. **Bắt đầu với QtCore**: Viết ứng dụng terminal trước khi làm GUI.
2. **Học về Qt Widgets**: Làm quen với giao diện và sự kiện.
3. **Tiến tới Qt nâng cao**: Làm việc với đa luồng, mạng, SQL.
4. **Thực hành dự án**: Xây dựng ứng dụng hoàn chỉnh.
5. **Tối ưu hóa & triển khai**: Tạo ứng dụng sẵn sàng cho thực tế.

📌 **Tài liệu tham khảo**:
- [Qt Documentation](https://doc.qt.io/)
- Sách "C++ GUI Programming with Qt"

