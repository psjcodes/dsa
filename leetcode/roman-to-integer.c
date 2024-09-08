/* 
just check the next char in special cases (IV, IX, etc)

also had switch case originally but wasnt as clean as this :/
*/

int getValue(const char* s){
    switch (*s) {
        case 'I': return (s[1] == 'V' || s[1] == 'X') ? -1 : 1;
        case 'X': return (s[1] == 'L' || s[1] == 'C') ? -10 : 10;
        case 'C': return (s[1] == 'D' || s[1] == 'M') ? -100 : 100;
        case 'V': return 5;
        case 'L': return 50;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char* s) {
    int sum = 0;
    for (; *s != '\0'; ++s) {
        sum += getValue(s);
    }
    return sum;
}