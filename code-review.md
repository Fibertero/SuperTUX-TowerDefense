# Recomendações:
Leia o [learncpp](https://www.learncpp.com), lá ensina como usar C++ da maneira correta, evitando problemas com memória, syntax e ainda recomendando um estilo de código.

O livro "cppnotes for professionals",

# Glossário:
|Tipo     | Descrição                                              |
|---------|--------------------------------------------------------|
| _Memory_| Código perigoso, provavelmente um vazamento de memória.|
| _Style_ | Não é obrigatório, mas acredito que deixe mais bonito. |
| _Modern_| Código moderno, recomendo utilizar.                    |

---

# main.cpp
## Style
 + `1~9`
	- Organizar alfabeticamente, recomendo usar o clang-format.
 + `40`
	- Recomendo que declare todas as variáveis no inicio do escopo.
 + `48 | 67 | 68`
	- Evite `inline if`, recomendo que deixe o statement uma linha abaixo do if.

## Modern
 + `16 | 25~36 | 40`
	- Use `value initialization` ao invés de `copy initialization`. [more info](https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization).

## Memory
 + `75`
	- Imagem `icon`, definida na linha 16, não foi descarregada com `UnloadImage`.

---

# src/dialogBox.cpp
## Style
 + `18~21 | 27 | 31`
	- Evite magic numbers, somente use quando você não vai reutilizar o valor em outro lugar, mas mesmo assim, tente definir uma constante nomeando o sentido do número. [more info](https://stackoverflow.com/a/3518945)

---

# src/fonts.cpp
## Memory
 + `3 | 4`
	- Variáveis no escopo de source(*.cpp) devem ser `static`, dessa forma tu evita acesso indevido dessas variáveis por outros arquivos. [more info](https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/)

---

# src/mapSelect.cpp
## Modern
 + `18~22`
	- Use constexpr para que essa evaluação seja explicitamente feita em compile-time. [more info](https://www.learncpp.com/cpp-tutorial/compile-time-constants-constant-expressions-and-constexpr/)
	- Use `auto` para inferir o tipo da variável. [more info](https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/)

---

# src/menu.hpp | src/options.hpp
## Modern
	- Use `inline` nas constantes, dessa forma o valor da constante é linkado externalmente, evitando que o linker tenha que linkar internamente todas as vezes que tu incluir o header. [more info](https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables)
## Style
	- Use `enum class`. Dê um escopo às constantes da enum, isso evita conflitos com variáveis externas. [more info](https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/)

---

# src/options.cpp
## Modern
 + `4~14`
	- Também use `static` nas funções em escopo de arquivo.

---

# src/player.hpp
## Modern
 + `3`
	- Em C++ não é necessário o uso de `typedef`, ao invés, use `using`. Neste caso, não é necessário o uso de `using`, a própria definição da struct já cria o tipo `playerData`. [using](https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/) | [struct](https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/)

    ```
    struct playerData{
		int points;
	};
	```

---
# All Classes
## Memory
 + Tente deixar as variáveis dentro do `private`, dessa forma tu evita acesso indevido dessas variáveis. [more info](https://www.learncpp.com/cpp-tutorial/public-vs-private-access-specifiers/)

# All Headers
## Memory
 + Use `header guards`, isso evita erros de duplicação de código. [more info](https://www.learncpp.com/cpp-tutorial/header-guards)

