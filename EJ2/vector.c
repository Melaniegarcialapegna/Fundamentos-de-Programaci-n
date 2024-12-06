#include "vector.h"

vector_t *vector_crear(size_t tam) {
    vector_t *vector =malloc(sizeof(vector_t));
    if (vector == NULL){
        return NULL;
    }
    vector->valores = malloc(tam*sizeof(int));
    if (vector->valores ==NULL || tam == 0){
        free(vector); 
        return NULL;
    }
    vector->tam =tam;
    return vector;
}

void vector_destruir(vector_t *vector) {
    free(vector->valores);
    free(vector);
}

bool vector_guardar(vector_t *vector, size_t pos, int valor) {
    if (vector->tam <= pos){
        return false;
    }
    vector->valores[pos]= valor;
    return true;
}

bool vector_obtener(vector_t *vector, size_t pos, int *valor) {
    if (vector->tam <= pos){
        return false;
    }
    *valor =vector->valores[pos];
    return true;
}

size_t vector_largo(vector_t *vector) {
    return vector->tam;
}

void vector_por_escalar(vector_t *vector, int k) {
    for(size_t i=0;i < vector->tam;i++) {
        vector->valores[i]*=k;
    }
}

vector_t* vector_sumar(vector_t *vector1, vector_t *vector2) {
    if (vector1 == NULL || vector2  == NULL){
        return NULL;
    }
    if (vector1->tam !=vector2->tam) {
        return NULL;
    }
    vector_t *vector_suma = vector_crear(vector1->tam);
    if(vector_suma == NULL){
        return NULL;
    }
    for (size_t i=0; i < vector1->tam; i++){
        vector_suma->valores[i]= vector1->valores[i] + vector2->valores[i];
    }
    return vector_suma;
}

bool vector_redimensionar(vector_t *vector, size_t nuevo_tam) {
    if (nuevo_tam==0) {
        return false;
    }
    int *valores_nuevos = malloc(nuevo_tam*sizeof(int));
    if (valores_nuevos ==NULL){
        return false;
    }
    size_t minimo_tam;
    minimo_tam= (nuevo_tam > vector->tam)? vector->tam:nuevo_tam;
    for(size_t i =0;minimo_tam> i;i++){
        valores_nuevos[i]= vector->valores[i];
    }
    free(vector->valores);
    vector->valores= valores_nuevos;
    vector->tam=nuevo_tam;
    return true;
}
