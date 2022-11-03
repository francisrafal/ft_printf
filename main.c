#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	ft_printf("String: %s\n", "This is a string.");
	ft_printf("Decimal: %d\n", 123456);
	ft_printf("Character: %c\n", 'a');
	ft_printf("Just one simple string.\n");
	return (0);
}
