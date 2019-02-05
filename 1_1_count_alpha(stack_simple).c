int		_isAlpha(char let)
{
	if (let >= 'a' && let <= 'z')
		return (1);
	else if (let >= 'A' && let <= 'Z')
		return (2);
	else
		return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2){
		printf("\n");
		return (0);
	}
	char 		hm[26] = {0};
	unsigned	cnt[26] = {0};
	char		flag = 0, key = 0;
	for (int i = 0; av[1][i]; i++){
		if ((flag = _isAlpha(av[1][i]))){
			key = (flag == 1) ? av[1][i] : av[1][i] + 32;
			for (int j = 0; j < 127; j++){
				if (!hm[j]){
					hm[j] = key;
					cnt[j]++;
					break ;
				} else if (hm[j] == key ){
					cnt[j]++;
					break ;
				}
			}
		}
	}
	for (int i = 0; hm[i]; i++){
		if (i != 0)
			printf(", ");
		printf("%d%c",cnt[i], hm[i]);
	}
	printf("\n");
	return (0);
}
