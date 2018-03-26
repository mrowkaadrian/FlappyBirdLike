#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Varnaxes {
	typedef std::unique_ptr<State> StateRef;

	class StateMachine {

	private:
		// ----- CLASS VARIABLES -----
		std::stack<StateRef> _states;
		StateRef _newState;
		bool _isRemoving, _isAdding, _isReplacing;

	public:
		// ----- CONSTRUCTOR/DESTRUCTOR -----
		StateMachine() {}
		~StateMachine() {}

		// ----- MEMBER FUNCTIONS -----
		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChanges();

		StateRef &GetActiveState();
	};
}