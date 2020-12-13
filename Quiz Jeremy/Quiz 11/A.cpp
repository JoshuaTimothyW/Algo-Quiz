#include <stdio.h>

int main () {
	FILE *fp = fopen("testdata.in", "r");
	int x;
	fscanf(fp,"%d\n", &x);
	char str[50][1009];
	int i = 0;
	
	while(fscanf(fp, " %[^#]#", str[i]) != EOF) {
		i++;
	}
	
	int count[20] = {0};
	
	for(int row = 0 ; row < i ; row++) {
		int j = 0;
		while(str[row][j] != '\0') {
			if(str[row][j] == ' ' || str[row][j] == '\n') {
				++count[row];
			}
			j++;
		}
	}
	
	int flag = 0;
	for(int row = 0 ; row < i ; row++) {
		if(count[row] < x) {
			printf("page %d: %d word(s)\n", row+1, count[row]);
			flag++;
		}
	}
	
	if(flag == 0) {
		puts("The essay is correct");
	}
	
	fclose(fp);
	return 0;
}
