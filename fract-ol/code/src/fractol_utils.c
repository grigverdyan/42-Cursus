double	*linspace(int start, int end)
{
	double	ls[100];
	int		i;

	i = 0;
	while (i < 100)
	{
		ls[i] = (double)(i) / (100.0 - 1.0);
		i++;
	}
	i = 0;
	while (i < 100)
	{
		printf("ls[%d] = %f\n", i, ls[i]);
		i++;
	}
	return (ls);
}
