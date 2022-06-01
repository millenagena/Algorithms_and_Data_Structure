typedef struct ponto Ponto;

Ponto *gera_pto();
float set_pto(Ponto *p, float x, float y);
float get_pto(Ponto *p, float *x, float *y);
float distancia_pto(Ponto *pto1, Ponto *pto2);
void libera_pto(Ponto **p);
