#include "buildactions.h"

BAVersion::BAVersion(const CGenerator *gen)
    :IBuildAction(gen)

{

}

void BAVersion::Execute(const CGenerator *gen)
{
    if(gen)generator = gen;
}



