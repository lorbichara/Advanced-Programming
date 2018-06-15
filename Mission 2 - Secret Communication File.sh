# Lorraine Bichara Assad A01193063
# february 26, 2018
# Mission 2: 
# Creation of a secret communication file with your field agent. You will be using one of the following books on Gutenberg project to embed information on it (https://www.gutenberg.org/browse/scores/top).
# Please follow the next rules:
# 	You will change the name of the protagonist with the name of your field agent through
# the document.
# 	You will change the name of the antagonist with the name of the target through the
# document.
# 	You will change the name of a prominent place on the story to the meeting place
# through the document.
# 	Finally, design a substitution method to convey date and time for the transaction using
# the rest of the text.

#!/bin/bash

# The Wizard Of Oz
# Name of field agent: Comet Hepburn (Replacing "Dorothy" and "DOROTHY")
# Name of target: Dr. Strangelove (Replacing "Wicked Witch of the West")
# Meeting place: Planet Moon 772 (Replacing "Emerald City")
# Date: 
# "	The month and year that appear as release date, are the month and year of when to meet: August 2018 (Replacing "July 2008").
# "	The day is the number that appears as EBook Number: 8 (Replacing "#55")
# "	The hour is the number that appears as first chapter The Cyclone: 12 (Replacing 1.)
# "	The minutes is the number that appears as the last chapter Home Again: 59 (Replacing 24.)


sed 's/Dorothy/Comet Hepburn/g;s/DOROTHY/Comet Hepburn/g;s/Wicked Witch of the West/Dr. Strangelove/g;s/Emerald City/Planet Moon 772/g;s/#55/#8/g;s/July/August/g;s/2008/2018/g;46s/1./12./g;69s/24./59./g' <WizardOfOz.txt >WizardOfOzNew.txt
