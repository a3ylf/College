; Alexandre Rodrigues 
; Anna dos Santos

.686
.model flat, stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\kernel32.lib
include \masm32\include\masm32.inc
includelib \masm32\lib\masm32.lib

.data
    entradaHandle dd 0 ; Handle do arquivo de entrada
    saidaHandle dd 0 ; Handle do arquivo de saida
    arquivoEntrada db 50 dup(0) ; Variável do nome do arquivo de entrada
    arquivoSaida db 50 dup(0) ; Variável do nome do arquivo de saida
    inputHandle dd 0 ; Handle de entrada do console
    outputHandle dd 0 ; Handle de saida do console
    console_count dd 0 ; Contador de caracteres do console

    output1 db "Nome do arquivo de entrada: ", 0 ; Saida 1
    output2 db "Nome do arquivo de saida: ", 0 ; Saida 2
    output3 db "Digite a coordenada x inicial: ", 0 ; Saida 3
    output4 db "Digite a coordenada y inicial: ", 0 ; Saida 4
    output5 db "Digite a largura: ", 0 ; Saida 5
    output6 db "Digite a altura: ", 0 ; Saida 6

    buffer dd 6480 dup (0) ; Buffer para leitura e escrita das linhas
    lidos dd 0 ; Contador de bytes lidos
    escritos dd 0 ; Contador de bytes escritos
    LarImagem dword 0 ; Largura da imagem
    auxiliar db 50 dup(0) ; String auxiliar para leitura de dados
    xinicial dd 0 ; X inicial
    yinicial dword 0 ; Y inicial
    largura  dword 0 ; Largura da censura
    altura   dword 0 ; Altura da censura
    pixel dd 0,0,0  ; Representa um pixel preto
    atual dword 0 ; Coordenada atual
    yatual dword 0 ; Coordenada y atual
    xatual dword 0 ; Coordenada x atual
    counter dword 0 ; Contador
    
.code
start:
    ; Pega as entradas e mostra as saidas
    invoke GetStdHandle, STD_INPUT_HANDLE
    mov inputHandle, eax
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov outputHandle, eax   

    ; Mostrar na tela a 1° saída e pega a primeira entrada (nome do arquivo de entrada)
    invoke WriteConsole, outputHandle, addr output1, sizeof output1 - 1, addr console_count, NULL
    invoke ReadConsole, inputHandle, addr arquivoEntrada, sizeof arquivoEntrada, addr console_count, NULL
    
    ; Trecho fornecido pelo professor para tratamento de entrada
    mov esi, offset arquivoEntrada
proximo:
    mov al, [esi]
    inc esi 
    cmp al, 13
    jne proximo
    dec esi
    xor al, al
    mov [esi], al 

    ; Mostrar na tela a 2° saída e pega a segunda entrada (nome do arquivo de saída)
    invoke WriteConsole, outputHandle, addr output2, sizeof output2 - 1, addr console_count, NULL
    invoke ReadConsole, inputHandle, addr arquivoSaida, sizeof arquivoSaida, addr console_count, NULL

    mov esi, offset arquivoSaida 
proximos:
    mov al, [esi] 
    inc esi 
    cmp al, 13
    jne proximos
    dec esi
    xor al, al
    mov [esi], al 

    ; Mostrar na tela as outras saidas, pegas os valores os coloca em uma variável auxiliar para o tratamento
    invoke WriteConsole, outputHandle, addr output3, sizeof output3 - 1, addr console_count, NULL
    invoke ReadConsole, inputHandle, addr auxiliar, sizeof auxiliar, addr console_count, NULL

    mov esi, offset auxiliar
prox1:
    mov al, [esi] 
    inc esi 
    cmp al, 48 
    jl terminar
    cmp al, 58
    jl prox1
terminar:
    dec esi 
    xor al, al 
    mov [esi], al 

    ; converte de string para inteiro e guarda na variável especifica
    invoke atodw, addr auxiliar
    mov xinicial, eax

    invoke WriteConsole, outputHandle, addr output4, sizeof output4 - 1, addr console_count, NULL
    invoke ReadConsole, inputHandle, addr auxiliar, sizeof auxiliar, addr console_count, NULL

    mov esi, offset auxiliar
prox2:
    mov al, [esi] 
    inc esi 
    cmp al, 48 
    jl terminar2
    cmp al, 58
    jl prox2
terminar2:
    dec esi 
    xor al, al 
    mov [esi], al 

    invoke atodw, addr auxiliar
    mov yinicial, eax

    invoke WriteConsole, outputHandle, addr output5, sizeof output5 - 1, addr console_count, NULL
    invoke ReadConsole, inputHandle, addr auxiliar, sizeof auxiliar, addr console_count, NULL

    mov esi, offset auxiliar
prox3:
    mov al, [esi] 
    inc esi 
    cmp al, 48 
    jl terminar3
    cmp al, 58
    jl prox3
terminar3:
    dec esi 
    xor al, al 
    mov [esi], al 

    invoke atodw, addr auxiliar
    mov largura, eax

    invoke WriteConsole, outputHandle, addr output6, sizeof output6 - 1, addr console_count, NULL
    invoke ReadConsole, inputHandle, addr auxiliar, sizeof auxiliar, addr console_count, NULL

    mov esi, offset auxiliar
prox4:
    mov al, [esi] 
    inc esi 
    cmp al, 48 
    jl terminar4
    cmp al, 58
    jl prox4
terminar4:
    dec esi 
    xor al, al 
    mov [esi], al 

    invoke atodw, addr auxiliar
    mov altura, eax

    invoke CreateFile, ADDR arquivoEntrada, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    mov entradaHandle, eax

    invoke ReadFile, entradaHandle, ADDR buffer, 18, ADDR lidos, 0

    invoke CreateFile, ADDR arquivoSaida, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
    mov saidaHandle, eax

    ; Escreve os primeiros 18 bytes no arquivo de saída
    invoke WriteFile, saidaHandle, ADDR buffer, 18, ADDR escritos, 0

    ; Ler o tamanho da largura da imagem do cabeçalho e armazena na variável
    invoke ReadFile, entradaHandle, ADDR buffer, 4, ADDR lidos, 0
    invoke WriteFile, saidaHandle, ADDR buffer, 4, ADDR escritos, 0
    mov eax, buffer
    imul eax, 3
    mov LarImagem, eax

    ; Ler os 32 bytes restantes do cabeçalho da imagem e os escreve no arquivo de saída
    invoke ReadFile, entradaHandle, ADDR buffer, 32, ADDR lidos, 0
    invoke WriteFile, saidaHandle, ADDR buffer, 32, ADDR escritos, 0

    ;altura salvará o "yfinal"
    mov eax, altura
    add eax, yinicial
    mov altura, eax
    
    ;largura salvará o "xfinal" ,ambos multiplicados por 3 pois 1 pixel = r + g + b
    mov eax, xinicial
    imul eax, 3 
    mov xinicial, eax
    mov eax, largura
    imul eax, 3 
    add eax, xinicial
    mov largura, eax

desenharPixels:
    mov xatual, 0
    
    mov ebx, counter
   ;checar se y está nas posições a serem censuradas 
    cmp ebx, dword ptr [yinicial]
    jbe  naoCensurar
    
    cmp ebx, dword ptr[altura]
    jg naoCensurar
    
    inc counter
    
    jmp censurar

naoCensurar:
    inc counter
    invoke ReadFile, entradaHandle, ADDR buffer, LarImagem, ADDR lidos, 0
    cmp lidos, 0
    je loopTerminado
    
    invoke WriteFile, saidaHandle, ADDR buffer, LarImagem, ADDR escritos, 0
    jmp desenharPixels
    
censurar:
 
    mov ebx, xatual
    
    mov eax, LarImagem
    cmp eax, ebx
    jbe desenharPixels

    invoke ReadFile, entradaHandle, ADDR buffer, 3, ADDR lidos, 0
    cmp lidos, 0
    je loopTerminado

    ;checar se x está na posição a ser censurada
    cmp ebx, dword ptr [xinicial]
    jbe naocensurarLoop
    
    cmp ebx, dword ptr [largura]
    jg naocensurarLoop

    jmp censurarLoop

censurarLoop:
    add xatual, 3
   invoke WriteFile, saidaHandle, ADDR pixel, 3, ADDR escritos, 0
    jmp censurar
    
naocensurarLoop:
    add xatual, 3
    invoke WriteFile, saidaHandle, ADDR buffer, 3, ADDR escritos, 0
    jmp censurar

loopTerminado:
    ; Fecha os handles dos arquivos e encerra o programa
    invoke CloseHandle, entradaHandle
    invoke CloseHandle, saidaHandle
    invoke ExitProcess, 0

end start
