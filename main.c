#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	ft_printf("s", "This is a string.");
	ft_printf("d", 123456);
	ft_printf("c", 'a');
	return (0);
}
