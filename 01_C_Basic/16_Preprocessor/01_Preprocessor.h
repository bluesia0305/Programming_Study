// 2022-06-28 수업


// 전처리 지시어(Preprocessing directive)
// : 컴파일이 진행되기 직전에 컴파일러에게 명령을 처리하도록 지시할 때 사용하는 구문.
//   * 전처리문은 '#'으로 시작되며, 한 줄에 한 개의 전처리기 명령만을 사용할 수 있음.
//   * 전처리문의 끝에는 ';'을 작성하지 않는다.


#pragma once
// #pragma: 컴파일러의 기능을 확장시킬 수 있도록 하는 지시어
// #pragma once: 컴파일러에게 해당 파일이 한 번만 포함하도록 지시.


#pragma warning (disable : 4996)
// #pragma warning ( disable : {error_code} ): 지정한 code의 경고 메세지를 무시.


#pragma region Region
#pragma endregion
// #pragma region {region_name}: 확장/축소시킬 수 있는 코드블럭 영역을 지정함. 
// #pragma endregion: 지정한 영역의 끝을 표시함.


#include <iostream>
// #include {file_name}: 지정한 파일의 내용을 읽어와 지시어가 작성된 파일에 포함시킴.
// * 헤더파일(.h): 소스 코드 문에서 사용할 내용들이 정의되어있는 파일.
//                헤더 파일을 포함시킴으로써 헤더 파일에 선언되어있는 함수, 변수 등을 사용할 수 있음.
//   - 기본 제공 헤더 파일: Visual Studio에서 기본적으로 제공하는 헤더 파일이며 <,>를 사용하여 추가할 수 있음.
//   - 사용자 정의 헤더 파일: 사용자가 직접 작성한 헤더 파일이며 ","를 사용하여 추가할 수 있음.


#define DEBUG
// #define {name}: 심볼, 또는 매크로 상수 및 함수를 정의하는 지시어.
#define PI 3.14f			// (매크로 상수 정의) 3.14f 의 값을 PI라는 키워드로 정의하여 PI를 사용할 때 3.14f 라는 코드로 치환됨.
#define plus(x, y) (x + y)	// (매크로 함수 정의) plus(x, y)라는 코드를 사용시, (x + y)라는 코드로 치환됨 (* 치환될 때 (,)까지 같이 치환되므로 주의, 매개변수의 타입 사용 불가능).


#undef DEBUG
// #undef {name}: 정의된 심볼, 또는 매크로 상수 및 함수를 해제하는 지시어.


#define INT 1
#if INT
// #if {condition_statement}: 조건에 따라 컴파일 여부를 검사하는 지시어. 정수 또는 열거형 형식만을 사용할 수 있음.
#elif INT == 0
// #elif {condition_statement): 위 조건이 맞지 않는 조건 하에서 추가적인 검사를 지시하는 지시어.
#else
// #else: 모든 조건이 충족되지 않았을 때 컴파일을 지시하는 지시어.
#endif
// #endif: 전처리 if 조건문의 종료를 나타내는 명령어. #if 지시어를 사용할 경우 반드시 함께 사용되어야함.


#ifdef INT
// ifdef {name}: 심볼, 매크로 상수 및 함수가 정의되어있는지 검사하는 지시어. 마찬가지로 #endif와 함께 사용되어야 함.
#endif
#ifndef INT
// ifndef {name}: 심볼, 매크로 상수 및 함수가 정의되어있지 않은지 검사하는 지시어. 마찬가지로 #endif와 함께 사용되어야 함.
#endif