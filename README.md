# ft_printf

## Usage

git clone https://github.com/MathieuJouffroy/ft_printf.git && cd ft_printf && make

```c
#include "ft_printf.h"

int				main(void)
{
  int i;

  i = 42;
  ft_printf("value: %d\n", i);
  ft_printf("string: %s %s!\n", "Hello", "World");
	return (0);
}
// value: 42
// string: Hello World!
```

### Compiling with a program
```console
gcc -Wall -Werror -Wextra main.c 
```
