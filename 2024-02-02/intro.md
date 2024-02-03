# Introducere în limbajul de programare C++

## Structura generală a unui program

```cpp
#include <iostream>
using namespace std;

int main() {
    // instrucțiuni
    return 0;
    
}
```

`iostream` este o "bibliotecă" și conține funcții de afișare și citire (*input/output stream*).

`using namespace std;` folosește la a scurta anumite intrucțiuni (ex. `cout` în loc de `std::cout`, `cin` în loc de `std::cin` etc.).

`main` este funcția principală, în care se va regăsi tot codul scris de voi.

`return 0;` îi arată calculatorului faptul că programul s-a terminat cu succes. Orice alt cod în afară de `0` semnifică o eroare.
Puteți vedea efectul acestei instrucțiuni când rulați un program și jos scrie `Process returned 0`.

## Declarare și inițializare

Orice variabilă trebuie declarată înainte de a fi utilizată. Exemplu:

```cpp
int sum, numcif, rasp;  // numere întregi
double dist;            // numere reale
char c;                 // caractere ('a', 'b', '2' etc.)
bool ok, exist;         // valori adevărat/fals
```

Dacă o variabilă nu este citită de la tastatură, atunci ea trebuie inițializată: ori imediat la declarare, ori după declarare.

```cpp
// imediat la declarare
int sum = 0;
double dist = 4.35;

// sau:
bool ok;
...
ok = true;
```

Variabilele le puteți declara unde vreți (chiar și in afara funcției `main`). Important este să **le inițializați imediat înainte de a fi folosite prima dată!**

## Citire și afișare

Citire: `cin >> a >> b >> c;`

Afișare: `cout << x;`
Atenție când afișați mai multe valori! Ele trebuie separate prin spațiu (`" "`) sau *line break*/enter (`"\n"`). Exemplu:

```cpp
int a = 23, b = 5386, c = 356;
cout << a << b << c;  // afișează 235386356
cout << a << " " << b << " " << c; // afișează 23 5386 356
cout << a << "\n" << b << "\n" << c;
/* 
afișează:
23
5386
356
*/
```

## Comentarii

Probabil ați observat prin exemple fragmente care de genul: `// ...` sau `/* ... */`. Ele se numesc comentarii și sunt ignorate de calculator.
`// ...` este pentru comentariu pe o singură linie și `/* ... */` pentru mai multe linii.

