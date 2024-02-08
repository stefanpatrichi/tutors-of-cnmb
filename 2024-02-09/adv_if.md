# Aprofundare structura linară și alternativă

## xor

XOR (SAU exclusiv) este o operație logică prin care se verifică dacă cei doi biți/cele două valori de adevăr sunt diferite.
Nu o vom folosi, dar e bine de știut.

## Whitespaces

Recapitulare: `" "` pentru spațiu, `"\n"` pentru enter/line break/întrerupere de linie.

**Problemă:** Afișați cifrele pare lipite, apoi cu spațiu între ele, apoi fiecare pe o linie separată. Între fiecare dintre cele trei
variante lăsați câte un rând liber.
<details>
<summary>O soluție posibilă: </summary>

```cpp
#include <iostream>
using namespace std;

int main() 
{
    cout << "02468";
    cout << "\n\n";
    cout << "0 2 4 6 8";
    cout << "\n\n";
    cout << "0\n2\n4\n6\n8";
    return 0;
}
```
</details>

## Altfel dacă

Dacă prima intrucțiune dintr-un bloc `else` este un `if`, atunci `if`-ul se trece imediat după `else`.

**Observație.** Dacă un bloc cuprins între acolade cuprinde o singură instrucțiune, acoladele pot fi omise (și, eventual, instrucțiunea poate
fi mutată pe același rând). 

Exemplu: să se afișeze dacă un număr e strict pozitiv, strict negativ sau nul.

```cpp
if (x > 0)
{
    cout << "poz";
}
else
{
    if (x == 0)
    {
        cout << "zero";
    }
    else
    {
        cout << "neg";
    }
}
```

devine:

```cpp
if (x > 0)
    cout << "poz";
else if (x == 0)
    cout << "zero";
else
    cout << "neg"; 
```

sau chiar: 

```cpp
if (x > 0) cout << "poz";
else if (x == 0) cout << "zero";
else cout << "neg"; 
```

**Problemă:** Se dă un număr natural de la 1 la 12 reprezentând o lună. Afișați anotimpul corespunzător.
<details>
<summary>O soluție posibilă: </summary>

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int luna;
    cin >> luna;

    if (luna == 12 || luna == 1 || luna == 2) cout << "iarna";
    else if (luna >= 3 && luna <= 5) cout << "primavara";
    else if (luna >= 6 && luna <= 8) cout << "vara";
    else cout << "toamna";
    return 0;
}
```
</details>

**Problemă:** Se dă un număr natural mai mare ca 1000. Stabiliți dacă ultimele 3 cifre sunt ordonate crescător, descrescător sau nu sunt ordonate.
<details>
<summary>O soluție posibilă: </summary>

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int x;
    cin >> x;

    int uni = x % 10, zec = x / 10 % 10, sut = x / 100 % 10;

    if (sut > zec && zec > uni) cout << "crescator";
    else if (uni > zec && zec > sut) cout << "descrescator";
    else cout << "dezordonate";
    return 0;
}
```
</details>

## Maximul dintre $n$ numere

**Observație:** Dacă aveți `using namespace std;` în program (ar trebui să aveți) nu folosiți variabile cu numele `max` și `min`!
Sunt funcții de bibliotecă, predefinite.

Cazul $n = 2$: banal (implementați ca temă + pregătire pentru test!)

Cazul $n = 3$: Se poate lua pe subcazuri: $a < b < c$ sau $a < c < b$ sau $b < a < c$ sau $b < c < a$ sau $c < a < b$ sau $c < b < a$.

Cazul $n = 4$: Deja avem $4! = 24$ subcazuri, mult prea multe.

<details>
<summary>Rezolvare optimă: </summary>
Se pornește cu maximul ori ca o valoare foarte mică, ori ca primul număr. Se ia fiecare număr la rând și se verifică dacă este mai mare
decât maximul curent. Dacă da, atunci maximul curent devine numărul analizat. Altfel, maximul rămâne la fel și trecem la următorul număr.

Cod pentru $n = 3$:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int a, b, c;
    cin >> a >> b >> c;

    int maxi = a;
    if (b > maxi) maxi = b;
    if (c > maxi) maxi = c;

    cout << maxi;
    return 0;
}
```

</details>

## Modulo pentru circularitate/periodicitate

Operatorul `%` se citește `modulo` sau `mod`.

Considerăm șirul numerelor naturale:

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 etc.

Aplicând operația `% 4` tuturor acestor numere:

0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2 etc.

Deci `% 4` ne folosește dacă avem ceva ce se repetă în grupe de câte 4.

**Problemă:** Se dă un moment al zilei, în ore și minute, și un interval de timp, în minute. Afișați ce oră va fi
după respectivul interval de timp.

<details>
<summary>Soluție: </summary>
Exemplu: pentru ora 23:47 și un interval de timp de 35 min, ora va fi 00:22.

Alți operatori de atribuire: `a += b;` e echivalent cu `a = a + b;` etc.

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int ora, min, interval;
    cin >> ora >> min >> interval;

    min += interval;
    if (min >= 60) 
    {
        ora += min / 60;
        min %= 60;
    }

    if (ora > 24) ora %= 24;

    cout << ora << ' ' << min;
    return 0;
}
```
</details>

**Problemă:** Revenim cu altă soluție la problema anotimpurilor.
<details>
<summary>Soluție alternativă:</summary>

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int luna;
    cin >> luna;

    int anotimp = luna % 12 / 4; 
    if (anotimp == 0) cout << "iarna";
    else if (anotimp == 1) cout << "primavara";
    else if (anotimp == 2) cout << "vara";
    else cout << "toamna";
    return 0;
}
```
</details>

## Probleme greuțe

* **Problema zid**: Gigel vrea să construiască un zid între doi stâlpi verticali, aflați la distanța $D$ unul de altul. El dispune de $n$ cărămizi de lungime $l$ și înălțime $h$ pe care le așează orizontal, una după alta, ca în figură. Pe fiecare rând orizontal așează câte cărămizi încap, lăsând eventual un gol la capătul din dreapta. În sus el se oprește atunci când se termină cărămizile. Afișați înălțimea maximă a zidului construit. În exemplul din figură: dacă $D = 11$, $n = 8$, $l = 3$ și $h = 2$ atunci înălțimea maximă a zidului va fi 6 (3 cărămizi fiecare de înălțime 2).

![](https://www.algopedia.ro/wiki/index.php/File:P4-zid.svg)

<details>
<summary>Soluție: </summary>

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int d, n, l, h;
    cin >> d >> n >> l >> h;

    int pelung = d / l;
    int peinalt = n / pelung;
    if (n % pelung != 0) peinalt++;

    cout << peinalt * h;
    return 0;
}
```
</details>

* **Problema ecgr1**. Se dau numerele naturale $a$ și $b4, reprezentând coeficienții ecuației de gradul întâi $ax + b = 0$. Afișați soluțiile
**naturale** ale ecuației. **Atenție! Soluțiile pot fi în număr de zero, una sau o infinitate!! Aveți grijă la cazurile particulare!**

<details>
<summary>Soluție: </summary>

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int a, b;
    cin >> a >> b;

    if (a == 0) 
    {
        if (b == 0) cout << "inf";
        else cout << "vid";
    }
    else if (-b % a == 0) cout << -b / a;
    else cout << "vid";

    return 0;
}
```
</details>

## Recapitulare. Ce am învățat astăzi?

* operația XOR
* recapitulare whitespaces
* `else if`
* determinarea maximului dintre $n$ numere
* folosiri ale operatorului `%`
* operatori compuși de atribuire: `+=`, `-=`, `*=` etc.
* cum să abordăm probleme de gândire


