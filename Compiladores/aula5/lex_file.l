/* isto diz ao flex ler apenas um arquivo de entrada */
%option noyywrap
    /* inicie a primeira definicao por um tab */
    int qtPhoneNumbers = 0;
    int qtIsbn = 0;
    int qtIps = 0;
    int qtLinks = 0;
%%
"+"55" ""("[0-9]{2}")"" "9[0-9]{4}"-"[0-9]{4} {
    /* Increment the number of brazilian phone numbers */
    qtPhoneNumbers++;
}

978"-"[0-9]{2}"-"[0-9]{3}"-"[0-9]{4}"-"[0-9] {
    qtIsbn++;
}

[0-2][0-5][0-5]"."[0-2][0-5][0-5]"."[0-2][0-5][0-5] {
    qtIps++;
}

http[s]?"://"www".".+".".+("/".+)* {
    qtLinks++;
}

%%
/* programa principal */
void main() {
    yylex(); /* scanner gerado por Flex */
    printf("Brazilian phone numbers = %d\n", qtPhoneNumbers);
    printf("ISBN code = %d\n", qtIsbn);
    printf("IPs = %d\n", qtIps);
    printf("URLs = %d\n", qtLinks);
}
