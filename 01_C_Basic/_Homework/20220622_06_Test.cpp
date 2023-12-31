#include <iostream>

// Call-by-value 와 call-by-address 를 조사하여 서술해주세요.

// 1. Call-by-value
// 의미 : 특정 자료공간에 저장된 값을 복사하여 매개변수에 저장함으로써 값 자체에 대해 처리하는 방식.
// 장점 : 원래 자료공간에 저장되어있는 값이 변경되지 않고 유지된다.
// 단점 : 값을 저장하기 위한 자료공간에 대한 메모리 낭비가 있음. 원래 자료공간에 저장된 값을 변경할 수 없음.

// 2. Call-by-address
// 의미 : 특정 자료공간을 가리키는 주소값을 매개변수에 저장함으로써 주소를 통해 간접접근하여 처리하는 방식.
// 장점 : 주소값만을 저장하고 간접접근하므로 메모리 절약이 가능함. 원래 자료공간에 저장되어있는 값을 변경할 수 있음.
// 단점 : 원래 자료공간에 저장되어있는 값이 변경되어 손실될 수 있음.