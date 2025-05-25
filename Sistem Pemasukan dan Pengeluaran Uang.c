#include <stdio.h>

// Deklarasi Fungsi
void menu(); // Menampilkan pilihan menu
void laporan_pemasukan(float *jumlahSaldo); // mengerjakan transaksi pemasukan
void laporan_pengeluaran(float *jumlahSaldo); // Mengerjakan transaksi pengeluaran
void tampilkan_laporan_keuangan(float pemasukan, float pengeluaran, float jumlahSaldo); // Menampilkan laporan keuangan

int main() {

    // Deklarasi 
    float pemasukan = 0, pengeluaran = 0, jumlahSaldo = 0; // Menampilkan total pemasukan, total pengeluaran, dan total saldo saat ini
    int pilihan; // Menampilkan pilihan menu 
    
    printf("Program Laporan Keuangan\n"); // Judul sistem pemrograman ini, yaitu "Program Laporan Keuangan"
    
    while(1) {
        menu(); // Menampilkan menu
        printf("Pilih menu (1-4): ");
        scanf("%d", &pilihan);
        
        if(pilihan == 1) { // laporan pemasukan pengguna
            laporan_pemasukan(&jumlahSaldo);
            pemasukan += jumlahSaldo;
        } 
        else if(pilihan == 2) { // Laporan pengeluaran pengguna
            laporan_pengeluaran(&jumlahSaldo);
            pengeluaran += jumlahSaldo;
        } 
        else if(pilihan == 3) { // menampilkan laporan keuangan
            tampilkan_laporan_keuangan(pemasukan, pengeluaran, jumlahSaldo);
        } 
        else if(pilihan == 4) { // program telah selesai
            printf("Program Finished.\n");
        } 
        else { // pilihan menu tidak valid
            printf("Pilihan tidak valid, pilih menu kembali!\n");
        }
    }
    
    return 0;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Laporan Pemasukan\n"); // tambah pemasukan
    printf("2. Laporan Pengeluaran\n"); // tambah pengeluaran
    printf("3. Tampilkan Laporan Keuangan\n"); // lihat laporan keuangan
    printf("4. Keluar\n"); // keluar dari program
}

void laporan_pemasukan(float *jumlahSaldo) { // Fungsi untuk mencatat pemasukan keuangan
    float jumlah; // Menyimpan laporan jumlah pemasukan
    printf("Masukkan jumlah pemasukan: ");
    scanf("%f", &jumlah);
    if(jumlah <= 0) {
            printf("Input tidak valid, masukkan jumlah positif!  "); // tidak akan bisa melakukan transaksi pemasukan jika <= 0. Program akan minta input ulang
            scanf("%f", &jumlah);
        }
        else {
        }
    *jumlahSaldo += jumlah; // saldo bertambah
    printf("Berhasil mencatat pemasukan %.2f\n", jumlah);
}

void laporan_pengeluaran(float *jumlahSaldo) { //Fungsi untuk mencatat pengeluaran keuangan
    float jumlah;  // Menyimpan laporan jumlah pengeluaran
    printf("Masukkan jumlah pengeluaran: ");
    scanf("%f", &jumlah);
    
    if(jumlah > *jumlahSaldo) {
        printf("Saldo tidak cukup!\n"); // tidak bisa melakukan transaksi pengeluaran, karena saldo tidak cukup
    } else {
        *jumlahSaldo -= jumlah; // saldo akan berkurang, jika transaksi mencukupi
        printf("Berhasil mencatat pengeluaran %.2f\n", jumlah);
    }
}

void tampilkan_laporan_keuangan(float pemasukan, float pengeluaran, float jumlahSaldo) { // Fungsi untuk menampilkamn laporan keuangan
    printf("\nLaporan Keuangan:\n");
    printf("Total Pemasukan: Rp%.2f\n", pemasukan); // Tampilkan total pemasukan
    printf("Total Pengeluaran: Rp%.2f\n", pengeluaran); // Tampilkan total pengeluaran
    printf("Saldo Saat Ini: Rp%.2f\n", jumlahSaldo); // Tampilkan total saldo saat ini
}
