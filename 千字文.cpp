#include <stdio.h>
struct hanzi
{
	int val;
	unsigned char s[5];
}f[65535];
int main()
{
	unsigned char c,d,e,k;
	int l,i,n=0;
	for (i = 1; i <=65535; i++){
		f[i].val = 0;
	}
	while (scanf("%c", &c) != EOF){
		if ((c >> 4) < 8){
			continue;
	}
		else if ((c >> 4) == 15){
			d = getchar();
			e = getchar();
			k = getchar();
			l = ((c & 7) << 18) + ((d & 63) << 12) + ((e & 63) << 6) + (k & 63);
			f[l].val++;
			f[l].s[0] = c;
			f[l].s[1] = d;
			f[l].s[2] = e;
			f[l].s[3] = k;
			f[l].s[4] = '\0';
		}
		else if ((c >> 4) == 14){
			d = getchar();
			e = getchar();
			l = ((c & 15) << 12) + ((d & 63) << 6) + (e & 63);
			f[l].val++;
			f[l].s[0] = c;
			f[l].s[1] = d;
			f[l].s[2] = e;
			f[l].s[3] = '\0';
		}
		else if ((c >> 4) >= 12){
			d = getchar();
			l = ((c & 31) << 6) + (d & 63);
			f[l].val++;
			f[l].s[0] = c;
			f[l].s[1] = d;
			f[l].s[2] = '\0';
		}
	}
	for (i = 1; i <= 65535; i++){
		if (f[i].val > 1){
			printf("%s 0x%04x %d\n", f[i].s,i,f[i].val);
			n = 1;
		}
	}
	if (n == 0)
		printf("No repeat!\n");
	return 0;

}

