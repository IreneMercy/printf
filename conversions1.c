/**
 * print_binary - print unsigned integer to binary
 * @arg: unsigned integer to print
 * Return: integer printed
 */
int print_binary(va_list arg)
{
	unsigned int i = va_arg(arg, unsigned int);
	int len = 0;
	int bin_arr[32];
	int x;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (i > 0)
	{
		bin_arr[len] = i % 2;
		i /= 2;
		len++;
	}

	for (x = len - 1; x >= 0; x--)
	{
		write(1, &bin_arr[x], 1);
	}

	return (len);
}
