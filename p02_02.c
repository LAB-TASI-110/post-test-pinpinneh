#include <stdio.h>

int main(void) {
    int jumlah_data;

    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &jumlah_data);

    if (jumlah_data <= 0) {
        printf("Jumlah data harus lebih dari 0.\n");
        return 1; 
    }

   int deret_stok[jumlah_data];

    
    printf("Masukkan %d deret stok (pisahkan dengan spasi): ", jumlah_data);
    for (int i = 0; i < jumlah_data; i++) {
        scanf("%d", &deret_stok[i]);
    }

    int kode_kategori;

  
    printf("Masukkan kode kategori (1 = Seragam/Ganjil, 2 = Sembako/Genap): ");
    scanf("%d", &kode_kategori);

    int total_stok = 0;

    
    for (int i = 0; i < jumlah_data; i++) {
        if (kode_kategori == 1 && (i % 2 == 0)) {
            total_stok += deret_stok[i];
        } 
        
        else if (kode_kategori == 2 && (i % 2 != 0)) {
            total_stok += deret_stok[i];
        }
    }

   
    printf("Total stok untuk kategori %d adalah: %d\n", kode_kategori, total_stok);

    return 0;
}