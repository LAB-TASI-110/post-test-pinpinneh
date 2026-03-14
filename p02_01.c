#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char kode[4];
    char nama[20];
    float ongkos_per_kg;
    bool luar_pulau;
} Kota;

bool cari_kota(const char* kode_input, Kota daftar_kota[], int jumlah_kota, Kota* kota_ditemukan) {
    for (int i = 0; i < jumlah_kota; i++) {
        if (strcmp(kode_input, daftar_kota[i].kode) == 0) {
            *kota_ditemukan = daftar_kota[i];
            return true;
        }
    }
    return false;
}

int main() {
    Kota daftar_kota[] = {
        {"MDN", "Medan", 8000.0, false},
        {"BLG", "Balige", 5000.0, false},
        {"JKT", "Jakarta", 12000.0, true},
        {"SBY", "Surabaya", 13000.0, true}
    };
    int jumlah_kota = sizeof(daftar_kota) / sizeof(daftar_kota[0]);

    char kode_input[10];
    float berat_butet;

    printf("=== Sistem Pengiriman Del-Express ===\n");
    printf("Masukkan kode kota dan berat (ketik 'END' untuk berhenti):\n\n");

    while (scanf("%s", kode_input) != EOF && strcmp(kode_input, "END") != 0) {
        scanf("%f", &berat_butet);

        Kota kota_tujuan;
        if (!cari_kota(kode_input, daftar_kota, jumlah_kota, &kota_tujuan)) {
            printf("Kode kota %s tidak valid!\n\n", kode_input);
            continue;
        }

        float berat_ucok = 1.5f * berat_butet; // Ucok = 3/2 x berat Butet
        float total_berat = berat_butet + berat_ucok;

      
        float ongkos_dasar = total_berat * kota_tujuan.ongkos_per_kg;
        float diskon = 0.0f;
        bool dapat_diskon = false;

        
        if (total_berat > 10.0f) {
            dapat_diskon = true;
            diskon = ongkos_dasar * 0.10f; 
        }

        float total_ongkos = ongkos_dasar - diskon;

        
        printf("      STRUK PEMBAYARAN DEL-EXPRESS      \n");
       
        printf("Kota Tujuan        : %s\n", kota_tujuan.nama);
        printf("Berat Paket Butet  : %.2f kg\n", berat_butet);