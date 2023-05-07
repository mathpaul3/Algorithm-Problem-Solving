#include <iostream>
using namespace std;

#define 프로그램시작 int main
#define 만약 if
#define 입력 cin
#define 출력 cout
#define 계속 while
#define 할때동안 &&true
#define 정수 int
#define 줄바꿈 '\n'
#define 모듈러 %
#define 더하기 +
#define 증가 ++
#define 나누기 /
#define 종료하기 return 0

#define 인원 N
#define 앞번호 precedent
#define 뒷번호 posterior
#define 라운드번호 cnt

프로그램시작() {
    정수 인원, 앞번호, 뒷번호, 라운드번호=0;
    입력 >> 인원 >> 앞번호 >> 뒷번호;
    만약 (앞번호>뒷번호) {
        앞번호 ^= 뒷번호;
        뒷번호 ^= 앞번호;
        앞번호 ^= 뒷번호;
    }
    계속 (인원!=1 할때동안) {
        인원 = (인원 나누기 2) 더하기 (인원 모듈러 2);
        라운드번호 증가;
        앞번호 = (앞번호 더하기 (앞번호 모듈러 2)) 나누기 2;
        뒷번호 = (뒷번호 더하기 (뒷번호 모듈러 2)) 나누기 2;
        만약 (앞번호 == 뒷번호) {
            출력 << 라운드번호 << 줄바꿈;
            종료하기;
        }
    }
    출력 << -1 << 줄바꿈;
    
    종료하기;
}