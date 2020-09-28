#include <stdio.h>
#include <string.h>
#define flush fflush(stdin);

int main(){
	
	long long total_income, total_pajak, list_year[10000], list_pph[10000], criteria_pajak[] = {50000000,250000000,500000000};
	char npwp[20],name[51],list_user[10000][51],list_npwp[10000][20];
	bool isNpwp;
	int spt,year,jenis_harta,year_npwp,month_npwp;
	
	long long uang_tunai[10000], tabungan[10000], giro[10000], deposito[10000];
	
	int menu=0, count=0, index=0,menu2=0;
	
	do{
		printf("Menu\n");
		printf("=============\n");		
		printf("1. Add\n");
		printf("2. Update\n");
		printf("3. Delete\n");
		printf("4. View\n");
		printf("5. Exit\n");
		
		do{
			printf("Input: ");
			scanf("%d",&menu); flush
		}while(menu < 1 || menu > 5);
		
		for(int i=0;i<25;i++){
			printf("\n");
		}
		
		switch(menu){
			case 1:
				
				do{
					printf("Formulir SPT Tahunan\n");
					printf("1. Formulir SPT Jenis 1770 S\n");
					printf("2. Formulir SPT Jenis 1770 SS\n");
					printf("3. Formulir SPT Jenis 1770\n");
					printf("Input: ");
					scanf("%d",&spt); flush
				}while(spt < 1 || spt > 3);
				
				do{
					printf("Input Tahun Pelaporan Pajak [4 digit]: ");
					scanf("%d",&year); flush
				}while(year < 1000 || year > 9999);
				
				menu2=0;
				do{
					printf("1. NPWP\n");
					printf("2. Non NPWP\n");
					printf("Input: ");
					scanf("%d",&menu2); flush
				}while(menu2 < 1 || menu2 > 2);
				
				switch(menu2){
					case 1:
						do{
							printf("Input Nomor NPWP [15 digit]: ");
							scanf("%[^\n]",&npwp); flush
							
							isNpwp = true;
							
							if(strlen(npwp) != 15){
								isNpwp = false;
							}else{
								for(int i=0;i<strlen(npwp);i++){
									if(npwp[i] >= '0' && npwp[i] <= '9'){
										continue;
									}else{
										isNpwp = false;
									}
								}	
							}
							
						}while( isNpwp == false );
						
						do{
							printf("Input Tahun Pendaftaran NPWP [4 digit]: ");
							scanf("%d",&year_npwp); flush
						}while(year_npwp < 1000 || year_npwp > 9999);
						
						do{
							printf("Input Bulan Pendaftaran NPWP [1-12]: ");
							scanf("%d",&month_npwp); flush
						}while(month_npwp < 1 || month_npwp > 12);
						
						
						strcpy(list_npwp[count],npwp);
						break;
					
					case 2:
						strcpy(list_npwp[count],"Non NPWP");
						break;
				}
				
				
				do{
					printf("Input Nama [5-50 Karakter]: ");
					scanf("%[^\n]",&name); flush
				}while(strlen(name) < 5 || strlen(name) > 50);
				
				uang_tunai[count] = 0;
				tabungan[count] = 0;
				giro[count] = 0;
				deposito[count] = 0;
				
				do{
					do{
						printf("Jenis Harta:\n");
						printf("1. 011 - Uang Tunai\n");
						printf("2. 012 - Tabungan\n");
						printf("3. 013 - Giro\n");
						printf("4. 014 - Deposito\n");
						printf("5. Done\n");
						printf("Input: ");
						scanf("%d",&jenis_harta); flush
					}while(jenis_harta < 1 || jenis_harta > 5);
					
					switch(jenis_harta){
						case 1:
							printf("Input Nominal Uang Tunai: ");
							scanf("%lld",&uang_tunai[count]);
							break;
						case 2:
							printf("Input Nominal Tabungan: ");
							scanf("%lld",&tabungan[count]);
							break;
						case 3:
							printf("Input Nominal Giro: ");
							scanf("%lld",&giro[count]);
							break;
						case 4:
							printf("Input Nominal Deposito: ");
							scanf("%lld",&deposito[count]);
							break;
					}
				}while(jenis_harta != 5);
				
				switch(spt){
					case 1:
						
						do{
							printf("Input Penghasilan Kena Pajak [Min 60 jt]: ");
							scanf("%lld",&total_income); flush
						}while(total_income < 60000001);

						break;
					case 2:
						
						do{
							printf("Input Penghasilan Kena Pajak [Max 60 jt]: ");
							scanf("%lld",&total_income); flush
						}while(total_income > 60000000);
						
						break;	
					
					case 3:
							printf("Input Penghasilan Kena Pajak: ");
							scanf("%lld",&total_income); flush
						
						break;
				}
		
				if(total_income <= criteria_pajak[0]){
		
					total_pajak = 0.05*total_income;	
				
				}else if(total_income > criteria_pajak[0] && total_income <= criteria_pajak[1]){
					
					total_pajak = 0.05*criteria_pajak[0] + 0.15*(total_income-criteria_pajak[0]);
					
				}else if(total_income > criteria_pajak[1] && total_income <= criteria_pajak[2]){
					
					total_pajak = 0.05*criteria_pajak[0] + 0.15*(criteria_pajak[1]-criteria_pajak[0]) + 0.25*(total_income-criteria_pajak[1]);
					
				}else if(total_income > criteria_pajak[2]){
					
					total_pajak = 0.05*criteria_pajak[0] + 0.15*(criteria_pajak[1]-criteria_pajak[0]) + 0.25*(criteria_pajak[2]-criteria_pajak[1]) + 0.3*(total_income-criteria_pajak[2]);
					
				}
				
				if(strcmp(list_npwp[count],"Non NPWP") == 0){
					total_pajak *= 1.2;
				}else{
					
					long long non_npwp_period, npwp_period, selisih;
					
					non_npwp_period = (month_npwp-1)*(total_pajak/12)*1.2;
					npwp_period = (month_npwp-1)*(total_pajak/12);
					selisih = non_npwp_period - npwp_period;
					
					if(year == year_npwp){
						total_pajak = non_npwp_period + (12-month_npwp+1) * total_pajak/12;
					}else if(year == year_npwp+1){
						total_pajak = total_pajak - selisih;
					}
					
				}
				
				list_year[count] = year;
				strcpy(list_user[count],name);
				list_pph[count] = total_pajak;
				 
				count++;
				printf("Add New Data!!!\n\n\n");
				
				break;
			case 2:
				if(count == 0){
					printf("No Data!\n\n\n");
				}else{
					printf("========================== View Data ==============================\n\n");
					for(int i=0;i<count;i++){
						printf("No : %d\n",i+1);
						printf("Tahun : %d\n",list_year[i]);
						printf("Nama : %s\n",list_user[i]);
						printf("NPWP : %s\n",list_npwp[i]);
						printf("Hasil Perhitungan Pajak Pribadi : %lld\n",list_pph[i]);
						printf("========================== Harta =========================\n");
						printf("Uang Tunai : %lld\n",uang_tunai[i]);
						printf("Tabungan : %lld\n",tabungan[i]);
						printf("Giro : %lld\n",giro[i]);
						printf("Deposito : %lld\n",deposito[i]);
						
						printf("==========================================================\n\n");
					}
					
					do{
						printf("Choose No. to update [input '0' to exit]: ");
						scanf("%d",&index); flush
					}while(index < 0 || index > count);
					
					if(index != 0){
						index--;
						do{
							printf("Formulir SPT Tahunan\n");
							printf("1. Formulir SPT Jenis 1770 S\n");
							printf("2. Formulir SPT Jenis 1770 SS\n");
							printf("3. Formulir SPT Jenis 1770\n");
							printf("Input: ");
							scanf("%d",&spt); flush
						}while(spt < 1 || spt > 3);
						
						do{
							printf("Input Tahun Pelaporan Pajak [4 digit]: ");
							scanf("%d",&year); flush
						}while(year < 1000 || year > 9999);
						
						menu2=0;
						do{
							printf("1. NPWP\n");
							printf("2. Non NPWP\n");
							printf("Input: ");
							scanf("%d",&menu2); flush
						}while(menu2 < 1 || menu2 > 2);
						
						switch(menu2){
							case 1:
								do{
									printf("Input Nomor NPWP [15 digit]: ");
									scanf("%[^\n]",&npwp); flush
									
									isNpwp = true;
									
									if(strlen(npwp) != 15){
										isNpwp = false;
									}else{
										for(int i=0;i<strlen(npwp);i++){
											if(npwp[i] >= '0' && npwp[i] <= '9'){
												continue;
											}else{
												isNpwp = false;
											}
										}	
									}
									
								}while( isNpwp == false );
								
								do{
									printf("Input Tahun Pendaftaran NPWP [4 digit]: ");
									scanf("%d",&year_npwp); flush
								}while(year_npwp < 1000 || year_npwp > 9999);
								
								do{
									printf("Input Bulan Pendaftaran NPWP [1-12]: ");
									scanf("%d",&month_npwp); flush
								}while(month_npwp < 1 || month_npwp > 12);
								
								strcpy(list_npwp[index],npwp);
								
								break;
							
							case 2:
								strcpy(list_npwp[index],"Non NPWP");
								break;
						}
						
						
						do{
							printf("Input Nama [5-50 Karakter]: ");
							scanf("%[^\n]",&name); flush
						}while(strlen(name) < 5 || strlen(name) > 50);
						
						uang_tunai[index] = 0;
						tabungan[index] = 0;
						giro[index] = 0;
						deposito[index] = 0;
						
						do{
							do{
								printf("Jenis Harta:\n");
								printf("1. 011 - Uang Tunai\n");
								printf("2. 012 - Tabungan\n");
								printf("3. 013 - Giro\n");
								printf("4. 014 - Deposito\n");
								printf("5. Done\n");
								printf("Input: ");
								scanf("%d",&jenis_harta); flush
							}while(jenis_harta < 1 || jenis_harta > 5);
							
							switch(jenis_harta){
								case 1:
									printf("Input Nominal Uang Tunai: ");
									scanf("%lld",&uang_tunai[index]);
									break;
								case 2:
									printf("Input Nominal Tabungan: ");
									scanf("%lld",&tabungan[index]);
									break;
								case 3:
									printf("Input Nominal Giro: ");
									scanf("%lld",&giro[index]);
									break;
								case 4:
									printf("Input Nominal Deposito: ");
									scanf("%lld",&deposito[index]);
									break;
							}
						}while(jenis_harta != 5);
						
						
						switch(spt){
							case 1:
								
								do{
									printf("Input Penghasilan Kena Pajak [Min 60 jt]: ");
									scanf("%lld",&total_income); flush
								}while(total_income < 60000000);
		
								break;
							case 2:
								
								do{
									printf("Input Penghasilan Kena Pajak [Max 60 jt]: ");
									scanf("%lld",&total_income); flush
								}while(total_income > 60000000);
								
								break;
							case 3:
									printf("Input Penghasilan Kena Pajak: ");
									scanf("%lld",&total_income); flush
								
								break;
						}
						
						if(total_income <= criteria_pajak[0]){
				
							total_pajak = 0.05*total_income;	
						
						}else if(total_income > criteria_pajak[0] && total_income <= criteria_pajak[1]){
							
							total_pajak = 0.05*criteria_pajak[0] + 0.15*(total_income-criteria_pajak[0]);
							
						}else if(total_income > criteria_pajak[1] && total_income <= criteria_pajak[2]){
							
							total_pajak = 0.05*criteria_pajak[0] + 0.15*(criteria_pajak[1]-criteria_pajak[0]) + 0.25*(total_income-criteria_pajak[1]);
							
						}else if(total_income > criteria_pajak[2]){
							
							total_pajak = 0.05*criteria_pajak[0] + 0.15*(criteria_pajak[1]-criteria_pajak[0]) + 0.25*(criteria_pajak[2]-criteria_pajak[1]) + 0.3*(total_income-criteria_pajak[2]);
							
						}

						
						if(strcmp(list_npwp[index],"Non NPWP") == 0){
							total_pajak *= 1.2;
						}else{
					
							long long non_npwp_period, npwp_period, selisih;
							
							non_npwp_period = (month_npwp-1)*(total_pajak/12)*1.2;
							npwp_period = (month_npwp-1)*(total_pajak/12);
							selisih = non_npwp_period - npwp_period;
							
							if(year == year_npwp){
								total_pajak = non_npwp_period + (12-month_npwp+1) * total_pajak/12;
							}else if(year == year_npwp+1){
								total_pajak = total_pajak - selisih;
							}
							
						}
						
						list_year[index] = year;
						strcpy(list_user[index],name);
						list_pph[index] = total_pajak;	
						printf("Updated Data!!!\n\n\n");
					}
				}
				break;
			case 3:
				if(count == 0){
					printf("No Data!\n\n\n");
				}else{
					printf("========================== View Data ==============================\n\n");
					for(int i=0;i<count;i++){
						printf("No : %d\n",i+1);
						printf("Tahun : %d\n",list_year[i]);
						printf("Nama : %s\n",list_user[i]);
						printf("NPWP : %s\n",list_npwp[i]);
						printf("Hasil Perhitungan Pajak Pribadi : %lld\n",list_pph[i]);
						printf("========================== Harta =========================\n");
						printf("Uang Tunai : %lld\n",uang_tunai[i]);
						printf("Tabungan : %lld\n",tabungan[i]);
						printf("Giro : %lld\n",giro[i]);
						printf("Deposito : %lld\n",deposito[i]);
						
						printf("==========================================================\n\n");
					}
					
					do{
						printf("Choose No. to delete [input '0' to exit]: ");
						scanf("%d",&index); flush
					}while(index < 0 || index > count);
					
					if(index != 0){
						for(int i=index-1;i<count;i++){
							list_year[i] = list_year[i+1];
							strcpy(list_user[i],list_user[i+1]);
							strcpy(list_npwp[i],list_npwp[i+1]);
							list_pph[i] = list_pph[i+1];
							uang_tunai[i] = uang_tunai[i+1];
							tabungan[i] = tabungan[i+1];
							giro[i] = giro[i+1];
							deposito[i] = deposito[i+1];
						}
						count--;
						printf("Deleted Data!!!\n\n\n");
					}
				}
				break;
			case 4:
				
				if(count == 0){
					printf("No Data!\n\n\n");
				}else{
					printf("========================== View Data ==============================\n\n");
					for(int i=0;i<count;i++){
						printf("No : %d\n",i+1);
						printf("Tahun : %d\n",list_year[i]);
						printf("Nama : %s\n",list_user[i]);
						printf("NPWP : %s\n",list_npwp[i]);
						printf("Hasil Perhitungan Pajak Pribadi : %lld\n",list_pph[i]);
						printf("========================== Harta =========================\n");
						printf("Uang Tunai : %lld\n",uang_tunai[i]);
						printf("Tabungan : %lld\n",tabungan[i]);
						printf("Giro : %lld\n",giro[i]);
						printf("Deposito : %lld\n",deposito[i]);
						
						printf("==========================================================\n\n");
					}
				}
				break;
		}
	}while(menu != 5);
	
	printf("\n");
	return 0;
}
