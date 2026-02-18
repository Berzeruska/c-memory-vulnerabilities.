# 🧠 Como o C Trata a Memória

## 1. Stack vs Heap
- **Stack** → Memória automática, usada para variáveis locais.  
- **Heap** → Memória dinâmica, alocada com `malloc()` e liberada com `free()`.  

## 2. Buffer Overflow
- Ocorre quando dados excedem o tamanho de um buffer.  
- Exemplo: `strcpy()` não verifica limites, podendo sobrescrever regiões críticas.  

## 3. Funções Perigosas
- `strcpy`, `gets`, `scanf("%s", ...)` → Não verificam limites.  
- Substituir por versões seguras: `strncpy`, `fgets`, `snprintf`.  

## 4. Boas Práticas
- Sempre validar tamanhos antes de copiar dados.  
- Usar ferramentas como **Valgrind** para detectar vazamentos de memória.  
- Adotar técnicas de **defesa em profundidade** (ASLR, Stack Canaries).  

## 5. Conclusão
O estudo de vulnerabilidades em C é essencial para compreender como ataques podem ocorrer e como preveni-los.  
