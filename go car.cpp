#include<stdio.h>
int main()
{
	int k, cou1, cou2, i;
	scanf("%d", &k);
	if (k < 49)
	{
		printf("yes\n");
		printf("+--------------------------+\n");
		cou1 = k / 4; cou2 = k % 4;
		if (cou1 == 11) {
			if(cou2==0) printf("|X.O.O.O.O.O.O.O.O.O.O.O.|D|)\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|\n|#.........................|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|)\n");
			if (cou2 == 1) printf("|O.O.O.O.O.O.O.O.O.O.O.O.|D|)\n|X.O.O.O.O.O.O.O.O.O.O.O.|.|\n|#.........................|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|)\n");
			if (cou2 == 2) printf("|O.O.O.O.O.O.O.O.O.O.O.O.|D|)\n|O.O.O.O.O.O.O.O.O.O.O.O.|.|\n|X.........................|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|)\n");
			if (cou2 == 3) printf("|O.O.O.O.O.O.O.O.O.O.O.O.|D|)\n|O.O.O.O.O.O.O.O.O.O.O.O.|.|\n|O.........................|\n|X.O.O.O.O.O.O.O.O.O.O.O.|.|\n|#.O.O.O.O.O.O.O.O.O.O.O.|.|)\n");

		}
		else if (cou1 == 12)
			printf("|O.O.O.O.O.O.O.O.O.O.O.O.|D|)\n|O.O.O.O.O.O.O.O.O.O.O.O.|.|\n|O.........................|\n|O.O.O.O.O.O.O.O.O.O.O.O.|.|\n|X.O.O.O.O.O.O.O.O.O.O.O.|.|)\n");
		else {
				printf("|");
				for (i = 0; i < 11 - cou1; i++)
					printf("#.");
				if (cou2 >= 1) printf("O."); 
				else if (cou2 == 0) printf("X.");else printf("#.");
				for (i = 0; i < cou1; i++) printf("O.");
				printf("|D|)\n");
				printf("|");
				for (i = 0; i < 11 - cou1; i++)
					printf("#.");
				if (cou2 >= 2) printf("O."); 
				else if (cou2 == 1) printf("X.");else printf("#.");
				for (i = 0; i < cou1; i++) printf("O.");
				printf("|.|\n");
			printf("|#.........................|\n");
			printf("|");
				for (i = 0; i < 11 - cou1; i++)
					printf("#.");
				if (cou2 >= 3) printf("O."); 
				else if (cou2 == 2) printf("X.");else printf("#.");
				for (i = 0; i < cou1; i++) printf("O.");
				printf("|.|\n");
				printf("|");
				for (i = 0; i < 11 - cou1; i++)
					printf("#.");
				if (cou2 == 3) printf("X."); else printf("#.");
				for (i = 0; i < cou1; i++) printf("O.");
				printf("|.|)\n");
			}
		printf("+--------------------------+\n");
	}
	else printf("no\n");
	return 0;
}