# TBIT_M ver.3
平衡3進法による論理回路をシミュレーションするためのライブラリです。比較のため、2進法による実装も含みます。

## 依存関係
- C++ 20

## セットアップ
ビット演算は`tbit_M.hpp`で宣言されています。
```cpp
#include "tbit_M.hpp"
```
四則演算を行うための関数は`tmath_M.hpp`に宣言されています。
```cpp
#include "tmath_M.hpp"
```
<br>
ビット演算は正確に動作しますが、四則演算は近似値を求めている都合上誤差が生じる可能性があります。

## Reference
`tmath_M`という名前空間の中に、4つのクラスと6つの関数があります。

### class bit
1ビットの2進数を扱うクラスです。
```cpp
tmath_M::bit a = '0';//'0' or '1'
```
`NOT`, `NAND`, `NOR`は以下のようにして求めれます。
```cpp
//NOT
tmath_M::bit b = a.n();//'1' <- '0'

//NAND
tmath_M::bit c = a & b;//'1' <- '0' & '1'

//NOR
tmath_M::bit d = a | b;//'0' <- '0' | '1'
```
`bit.data`から値を参照することができます。
```cpp
std::cout << a.data;//'0'
```

### class bits
複数ビットの2進数を扱うクラスです。
```cpp
tmath_M::bits a = 4;//"0000"
tmath_M::bits b = "0100";
tmath_M::bits c = { '0', '1', '0', '0' };
```
`bit`クラスと同様に`NOT`, `NAND`, `NOR`のビット演算を行うことができます。値を参照するには`bit.data()`又は`bit.value()`を使用します。`bit.size()`ではビットサイズを取得できます。

### class tbit
1ビットの平衡3進数を扱うクラスです。`1`, '0', 'T'のいずれかの状態を持ちます。
```cpp
tmath_M::tbit a = '1';
```
5種類の`NOT`と4種類のビット演算を処理できます。
```cpp
//NOT(type 10T)
tmath_M::tbit b = a.n10T();//'T' <- '1'

//NAND
tmath_M::tbit s = a & b;//'1' <- '1' & 'T'

//NOR
s = a | b;//'T' <- '1' | 'T'

//NCONS
s = a | b;//'0' <- '1' * 'T'

//NANY
s = a | b;//'0' <- '1' + 'T'
```

### class tbits
複数ビットの平衡3進法を扱うクラスです。
```cpp
tmath_M::tbits a = 4;//"0000"
tmath_M::tbits b = "010T";
tmath_M::tbits c = { '0', '1', '0', 'T' };
```
`tbit`クラスと同様のビット演算を行えます。

### HA
半加算器として機能します。
```cpp
auto [s, c] = tmath_M::HA(tmath_M::bit, tmath_M::bit)
auto [s, c] = tmath_M::HA(tmath_M::tbit, tmath_M::tbit)
```

### FA
全加算器です。
```cpp
auto [s, c] = tmath_M::HA(tmath_M::bit, tmath_M::bit, tmath_M::bit)
auto [s, c] = tmath_M::HA(tmath_M::tbit, tmath_M::tbit, tmath_M::tbit)
```

### ADD
加算を処理します。繰り上がり分`c`は`bit`クラスで表現されます。
```cpp
auto [s, c] = tmath_M::ADD(tmath_M::bits, tmath_M::bits)
auto [s, c] = tmath_M::ADD(tmath_M::tbits, tmath_M::tbit)
```

### SUB
減算を処理します。2進数では負の数を表現できないため、出力は正確ではありません。
```cpp
auto [s, c] = tmath_M::SUB(tmath_M::bits, tmath_M::bits)
auto [s, c] = tmath_M::SUB(tmath_M::tbits, tmath_M::tbits)
```

### MUL
乗算を処理します。出力のビットサイズは入力のビットサイズの2倍です。
```cpp
tmath_M::bits s = tmath_M::MUL(tmath_M::bits, tmath_M::bits)
tmath_M::tbits s = tmath_M::MUL(tmath_M::tbits, tmath_M::tbits)
```

### DIV
除算を処理します。ゴールドシュミット法による近似計算であるため、誤差が生じる場合があります。5ビットまでのビットサイズでは誤差が生じないように調整しています。
```cpp
tmath_M::bits s = tmath_M::DIV(tmath_M::bits, tmath_M::bits)
tmath_M::tbits s = tmath_M::DIV(tmath_M::tbits, tmath_M::tbits)
```

## 使用例
https://github.com/metaphysical-bard/TBIT_M/blob/main/src/example.cpp

## Version
| DATA | VERSION | INFO |
| :---: | ---: | :--- |
| 2025-06-09 | 1 | first commit |
| 2025-06-11 | 2 | add new namespace |
| 2025-06-11 | 3 | improve div<br>add test file |

## ライセンス
- `zlib License`です。
- プログラムの利用、複製、書き換え、再配布を許可します。
- 本プログラムにより生じた不利益に関して、本プログラムの製作者は責任を負いません。

## 連絡先
Ryoichi Tsukamoto<br>
contact : r03e24@hachinohe.kosen-ac.jp
