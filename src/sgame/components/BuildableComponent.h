#ifndef BUILDABLE_COMPONENT_H_
#define BUILDABLE_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class BuildableComponent: public BuildableComponentBase {
	public:
		typedef enum lifecycle_e {
			// Alive states.
			CONSTRUCTING,
			CONSTRUCTED,
			// Dead states.
			PRE_BLAST,
			POST_BLAST
		} lifecycle_t;

		// ///////////////////// //
		// Autogenerated Members //
		// ///////////////////// //

		/**
		 * @brief Default constructor of the BuildableComponent.
		 * @param entity The entity that owns the component instance.
		 * @param r_HealthComponent A HealthComponent instance that this component depends on.
		 * @param r_ThinkingComponent A ThinkingComponent instance that this component depends on.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		BuildableComponent(Entity& entity, HealthComponent& r_HealthComponent, ThinkingComponent& r_ThinkingComponent);

		/**
		 * @brief Handle the PrepareNetCode message.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandlePrepareNetCode();

		/**
		 * @brief Handle the Die message.
		 * @param killer
		 * @param meansOfDeath
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandleDie(gentity_t* killer, meansOfDeath_t meansOfDeath);

		// ///////////////////// //

		void Think(int timeDelta);

		lifecycle_t GetState() { return state; }
		void SetState(lifecycle_t state) { this->state = state; }

		/**
		 * @return Whether the buildable is currently marked for deconstruction.
		 */
		bool MarkedForDeconstruction() { return marked; }

		/**
		 * @return Time when the buildable was marked for deconstruction or 0 if it isn't currently marked.
		 */
		int  GetMarkTime() { return marked ? markTime : 0; }

		void SetDeconstructionMark() { marked = true; markTime = level.time; }
		void ClearDeconstructionMark() { marked = false; }
		void ToggleDeconstructionMark() { marked = !marked; if (marked) markTime = level.time; }

		/**
		 * @return Whether the buildable has completed construction and is alive and powered.
		 */
		bool Active();

	private:
		lifecycle_t state;

		bool marked;
		int  markTime;

		// TODO: Move gentity_t.deconstruct and gentity_t.powered here.
		//bool marked; /**< Marked for deconstruction. */
		//bool powered;
};

#endif // BUILDABLE_COMPONENT_H_
