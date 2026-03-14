#include <stdio.h>
#include <string.h>

struct Feedback
{
    int kategori;
    int rating;
    char kritik[200];
};

int main()
{
    struct Feedback fb;
    int pilihan;

    printf("=== Sistem Operasional Kafetaria IT Del ===\n");

    while (1)
    {
        printf("\n--- Form Kepuasan Pelanggan ---\n");
        printf("Pilih Kategori yang Ingin Dinilai:\n");
        printf("1. Kualitas Makanan\n");
        printf("2. Kebersihan\n");
        printf("3. Pelayanan\n");
        printf("4. Keluar & Lihat Rekap Terakhir\n");
        printf("Pilihan Anda (1-4): ");
        scanf("%d", &fb.kategori);

        if (fb.kategori == 4)
        {
            printf("Terima kasih telah membantu meningkatkan layanan kafetaria!\n");
            break;
        }

        if (fb.kategori < 1 || fb.kategori > 3)
        {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
            continue;
        }

        do
        {
            printf("Berikan Rating (1-5 Bintang): ");
            scanf("%d", &fb.rating);
            if (fb.rating < 1 || fb.rating > 5)
            {
                printf("Mohon masukkan angka 1 sampai 5.\n");
            }
        } while (fb.rating < 1 || fb.rating > 5);

        getchar();
        printf("Tuliskan Kritik/Saran Anda: ");
        fgets(fb.kritik, sizeof(fb.kritik), stdin);
        fb.kritik[strcspn(fb.kritik, "\n")] = 0;

        printf("\n[Sistem Terupdate] Feedback Berhasil Disimpan:\n");
        printf("- Kategori: %s\n", (fb.kategori == 1 ? "Makanan" : (fb.kategori == 2 ? "Kebersihan" : "Pelayanan")));
        printf("- Rating  : %d/5 Bintang\n", fb.rating);
        printf("- Kritik  : %s\n", fb.kritik);
        printf("------------------------------------------\n");
    }

    return 0;
}