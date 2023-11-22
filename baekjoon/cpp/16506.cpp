#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int rA, rD, sharpC;
        string opcode, assembly;

        cin >> opcode >> rD >> rA >> sharpC;
        bitset<3> rAbit(rA), rDbit(rD);
        bitset<4> sharpCbit((opcode[opcode.size()-1]=='C' ? sharpC : sharpC<<1));

        if (opcode=="ADD")      assembly += "00000";
        if (opcode=="ADDC")     assembly += "00001";
        if (opcode=="SUB")      assembly += "00010";
        if (opcode=="SUBC")     assembly += "00011";
        if (opcode=="MOV")      assembly += "00100";
        if (opcode=="MOVC")     assembly += "00101";
        if (opcode=="AND")      assembly += "00110";
        if (opcode=="ANDC")     assembly += "00111";
        if (opcode=="OR")       assembly += "01000";
        if (opcode=="ORC")      assembly += "01001";
        if (opcode=="NOT")      assembly += "01010";
        if (opcode=="MULT")     assembly += "01100";
        if (opcode=="MULTC")    assembly += "01101";
        if (opcode=="LSFTL")    assembly += "01110";
        if (opcode=="LSFTLC")   assembly += "01111";
        if (opcode=="LSFTR")    assembly += "10000";
        if (opcode=="LSFTRC")   assembly += "10001";
        if (opcode=="ASFTR")    assembly += "10010";
        if (opcode=="ASFTRC")   assembly += "10011";
        if (opcode=="RL")       assembly += "10100";
        if (opcode=="RLC")      assembly += "10101";
        if (opcode=="RR")       assembly += "10110";
        if (opcode=="RRC")      assembly += "10111";
        
        assembly += "0" + rDbit.to_string();
        if (opcode=="NOT" || (opcode.size()>2 && opcode.substr(0,3)=="MOV")) assembly += "000";
        else assembly += rAbit.to_string();
        assembly += sharpCbit.to_string();
        cout << assembly << '\n';
    }
    return 0;
}