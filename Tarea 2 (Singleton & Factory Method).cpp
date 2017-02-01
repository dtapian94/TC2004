class SfPersonaje
{
public:
	template<class T>
	static T* crearPersonaje()
	{
		T* elPersonaje = new T;
		elPersonaje->correr();
		return elPersonaje;

	}
};