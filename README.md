# TUCIL 2

## Deskripsi Singkat
Program ini digunakan untuk mengkompressi gambar yang  menjadi masukan serta membuat gif dari kompresi tersebut. Metode kompresi yang digunakan, mengikuti algoritma divide and conquer dengan memecah blok menjadi 4 dan diselesaikan satu persatu melewati metode yang dipilih (Variance, MAD, Pixel difference, Entropy, SSIM)

## 🛠️ Requirement dan Instalasi

Program ini dijalankan menggunakan `Makefile`, sehingga membutuhkan tool `make`.

### 💻 Sistem Operasi yang Didukung

- **Linux / macOS**  
  Sudah mendukung `make` secara default atau bisa diinstal dengan mudah menggunakan package manager.

- **Windows**  
  Diperlukan lingkungan yang mendukung `make`, seperti:

  - **WSL (Windows Subsystem for Linux)**  
    Rekomendasi utama. Install WSL (misalnya Ubuntu) dan jalankan perintah `make` dari terminal WSL.
    
  - **Git Bash**  
    Alternatif ringan. Pastikan `make` tersedia atau ditambahkan ke PATH.
    
  - **MSYS2 / MinGW**  
    Pilihan lain yang mendukung perintah `make` serta command Unix-like lainnya.

### 📦 Cara Instalasi `make` (Linux / WSL)

```bash
sudo apt update
sudo apt install make
```

## 🧾 Cara Mengkompilasi Program

1. **Masuk ke direktori folder tugas:**
2. **Buka terminal yang mendukung make:**
   - Linux / macOS: Terminal biasa
   - Windows: Gunakan WSL, Git Bash, atau MinGW
3. **Jalankan perintah build:**
```bash
make build
```

## 🧾 Cara menjalankan program

1. **Masuk ke direktori folder tugas:**
2. **Buka terminal yang mendukung make:**
   - Linux / macOS: Terminal biasa
   - Windows: Gunakan WSL, Git Bash, atau MinGW
3. **Jalankan perintah run:**
```bash
make run
```
4. **Melakukan build sekaligus run:**
```bash
make all
```
## 👥 Authors

- **Samuel Gerrard Hamonangan Girsang**  
  NIM: 13523064
  Universitas: Institut Teknologi Bandung (ITB)

- **Nadhif Al Rozin**  
  NIM: 13523076  
  Universitas: Institut Teknologi Bandung (ITB)

