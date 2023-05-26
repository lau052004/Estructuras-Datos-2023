#include <vector>
#include <queue>

// --------------- SE PRESENTAN LAS CLASES PROPORCIONADAS EN EL ENUNCIADO ----------------------------------//

class Jugador
{
    protected:
        int m_Numero;  
        float m_PosX;  
        float m_PosY; 
        float m_TamanoTerreno;  
    public:
        Jugador();  
        virtual ~Jugador();  
        float ObtenerDesempenoAtaque() const;  
        float ObtenerDesempenoDefensa() const; 
        float CalcularEfectividadHasta(const Jugador& otro) const; 
        int getm_Numero() const { return m_Numero; }  
};


class SituacionDeJuego 
{
    protected:
        std::vector<Jugador> m_Jugadores;
        float m_TamanoTerreno; 
    public:
        SituacionDeJuego(); 
        virtual ~SituacionDeJuego();  
        struct NodoSecuenciasOptimas 
        {
            int ElPaseVieneDesde;
        };

        typedef std::vector<NodoSecuenciasOptimas> SecuenciasOptimas;

        // Se realizó este cambio con la finalidad de retornar información un poco más completa acerca de lo que se pide calcular
        std::pair<SecuenciasOptimas, std::vector<float>> ObtenerSecuenciasOptimas(int numero, bool esAtaque) const;

        struct SecuenciaOptima
        {
            std::vector<int> Secuencia;
            float ProbabilidadFinal;
            bool TodosLosJugadores;
        };

        SecuenciaOptima ObtenerSecuenciaOptima(int numero, bool esAtaque) const;
};

// -----------------------------------------  INICIO DE LA SOLUCIÓN -------------------------------------------------------------------------------//

// PUNTO 1 
float Jugador::CalcularEfectividadHasta(const Jugador& otro) const {
    // Asignación de variables para poder realizar los cálculos de manera más sencilla
    float ax = this->m_PosX;
    float ay = this->m_PosY;
    float bx = otro.m_PosX;
    float by = otro.m_PosY;
    
    // Para calcular la distancia primero se calcula el denominador en "distancia"
    float distancia = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
    // Se calcula la efectividad
    float efectividad = 1 - (distancia / m_TamanoTerreno);
    
    return efectividad;
}


// PUNTO 2
std::pair<SituacionDeJuego::SecuenciasOptimas, std::vector<float>> SituacionDeJuego::ObtenerSecuenciasOptimas(int numero, bool esAtaque) const {
    // Creación de la lista de secuencias
    SecuenciasOptimas secuencias;  
    // Inicialización del vector de probabilidades
    std::vector<float> probabilidad(m_Jugadores.size(), 0);  
    // La probabilidad del jugador inicial se asigna como 1 ya que al no haber distancia consigo mismo tienen el valor máximo
    probabilidad[numero] = 1;  
    // Inicialización de los nodos de las secuencias
    for(int i = 0; i < m_Jugadores.size(); i++) {
        NodoSecuenciasOptimas node;
        // Se inicia en -1 para saber que no contiene un dato real aún
        node.ElPaseVieneDesde = -1;
        secuencias.push_back(node);
    }

    // IMPORTANTE: Para resolver el problema propuesto se utilizará la implementación del algoritmo DIJKSTRA con COLA DE PRIORIDAD

    // Inicialización de la cola de prioridad
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> priority_queue;
        // Insertamos el juagdor incial e la cola de prioridad (tiene la probabilidad más alta)
        priority_queue.push({1, numero}); 
         
        // Se inicia el ciclo para ejecutar el algoritmo Dijstra mientras la cola de prioridad no esté vacía
        while(!priority_queue.empty()) {
            // Probabilidad actual
            float pActual = priority_queue.top().first; 
            // Jugador actual
            int jActual = priority_queue.top().second;  
            priority_queue.pop();
            // Bucle para recorrer todos los jugadores
            for(int i = 0; i < m_Jugadores.size(); i++) {
                // Comprobar que no se tenga en cuenta al jugador actual
                if (i != jActual) {
                    // Calcular la nueva probabilidad
                    float efectividadPase = m_Jugadores[jActual].CalcularEfectividadHasta(m_Jugadores[i]);
                    float nuevaProb = pActual * efectividadPase;
                    
                    // Si la nueva probabilidad es mayor que la actual, se actualiza la probabilidad y se inserta el jugador en la cola
                    if (secuencias[i].ElPaseVieneDesde == -1 || nuevaProb > probabilidad[i]) {
                        secuencias[i].ElPaseVieneDesde = jActual;
                        probabilidad[i] = nuevaProb;
                        priority_queue.push({nuevaProb, i});
                    }
                }

            }
        }

    return {secuencias, probabilidad}; 
}


// PUNTO 3
SituacionDeJuego::SecuenciaOptima SituacionDeJuego::ObtenerSecuenciaOptima(int numero, bool esAtaque) const {
    // Inicialización del jugador con mejor rendimiento (se usa -1 por que este no puede ser el número de ningún jugador ni de una probabilidad)
    float masRendimiento = -1;  
    int jugadormasRendimiento = -1;  

    // Ciclo for-each para todos los jugadores -> encontrar el jugador con el mejor rendimiento
    for(const Jugador& jugador : m_Jugadores) {
        float desempeno = esAtaque ? jugador.ObtenerDesempenoAtaque() : jugador.ObtenerDesempenoDefensa();
        if(desempeno > masRendimiento) {
            masRendimiento = desempeno;
            jugadormasRendimiento = jugador.getm_Numero();
        }
    }

    // Se obtienen las secuencias y las probabilidades con el uso de la función del punto 2
    std::pair<SecuenciasOptimas, std::vector<float>> SecOptimas = ObtenerSecuenciasOptimas(numero, esAtaque);
    SecuenciasOptimas secuencias = SecOptimas.first;
    std::vector<float> probabilidad = SecOptimas.second;
    // Inicialización de la secuencia óptima
    SecuenciaOptima secuenciaOptima; 
    // Inicialización del jugador actual
    int jActual = jugadormasRendimiento;  
    // Inicialización del indicador de todos los jugadores
    bool todos = true;  

    // Se construye la secuencia más optima
    while(jActual != numero) {
        // Inserta el jugador actual en la secuencia
        secuenciaOptima.Secuencia.insert(secuenciaOptima.Secuencia.begin(), jActual);  
        // Si el jugador actual no tiene un pase de entrada, no están todos los jugadores
        if(secuencias[jActual].ElPaseVieneDesde == -1) todos = false;
        // Se actualiza el jugador actual
        jActual = secuencias[jActual].ElPaseVieneDesde;  
    }

    // Se inserta el jugador inicial en la secuencia, se establece la probabilidad final y se establece el indicador de todos los jugadores
    secuenciaOptima.Secuencia.insert(secuenciaOptima.Secuencia.begin(), numero); 
    secuenciaOptima.ProbabilidadFinal = probabilidad[jugadormasRendimiento];  
    secuenciaOptima.TodosLosJugadores = todos;  

    // Retorna la secuencia óptima
    return secuenciaOptima;  
}
