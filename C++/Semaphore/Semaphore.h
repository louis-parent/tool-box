#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#define DEFAULT_KEY "__SEMAPHORE_H__"

#include <string>

namespace std
{
	class Semaphore
	{
		private:
			int id;
			
			bool update(signed int token);
			
		public:
			Semaphore() : Semaphore(0) {}
			Semaphore(const std::string& key) : Semaphore(key, 0) {}
			Semaphore(int tokens) : Semaphore(DEFAULT_KEY, tokens) {}
			Semaphore(const std::string& key, int tokens);
			
			bool init(int tokens);
			bool clear();
			
			bool down() { return this->down(1); }
			bool down(unsigned int tokens) { return this->P(tokens); }
			
			bool wait() { return this->wait(1); }
			bool wait(unsigned int tokens) { return this->P(tokens); }
			
			bool acquire() { return this-> acquire(1); }
			bool acquire(unsigned int tokens) { return this->P(tokens); }
			
			bool procure() { return this->procure(1); }
			bool procure(unsigned int tokens) { return this->P(tokens); }
			
			bool P() { return this->P(1); }
			bool P(unsigned int tokens) { return this->update((signed) tokens * -1); }
			
			bool up() { return this->up(1); }
			bool up(unsigned int tokens) { return this->V(tokens); }
			
			bool signal() { return this->signal(1); }
			bool signal(unsigned int tokens) { return this->V(tokens); }
			
			bool release() { return this->release(1); }
			bool release(unsigned int tokens) { return this->V(tokens); }
			
			bool vacate() { return this->vacate(1); }
			bool vacate(unsigned int tokens) { return this->V(tokens); }
			
			bool V() { return this->V(1); }
			bool V(unsigned int tokens) { return this->update((signed) tokens); }
			
			void waitForZero() { this->Z(); }
			
			void Z() { this->update(0); }
	};
}

#endif
