/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 15:47:18 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:54:29 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Lists.hpp"

const std::string wildMagicList[] = {
    "Roll a d10. On a 1-2, you cast Fireball as a 3rd-level spell centered on yourself.",
    "Your skin turns a vibrant shade of blue. A Remove Curse spell can end this effect.",
    "An eye appears on your forehead for the next minute. During that time, you have advantage on Wisdom (Perception) checks that rely on sight.",
    "You teleport up to 60 feet to an unoccupied space of your choice that you can see.",
    "You are frightened by the nearest creature until the end of your next turn.",
    "You gain resistance to all damage for the next minute.",
    "Your hair falls out but grows back within 24 hours.",
    "For the next minute, all your spells with a casting time of 1 action have a casting time of 1 bonus action.",
    "You cast Confusion centered on yourself.",
    "You turn into a potted plant until the start of your next turn. While a plant, you are incapacitated and have vulnerability to all damage. If you drop to 0 hit points, your pot breaks, and your form reverts.",
    "You regain 5d10 hit points.",
    "Your feet grow to three times their normal size for the next minute. This increases your walking speed by 10 feet and grants you advantage on Strength checks and Strength saving throws.",
    "You cast Fly on a random creature within 60 feet of you. The target can't concentrate on the spell and must make a Concentration saving throw DC 10 to avoid falling.",
    "You become invisible for 1 minute. Anything you are wearing or carrying is invisible as long as it is on your person.",
    "You age 1d10 years. You can revert this effect with a Greater Restoration spell.",
    "You cast Slow on yourself for the next minute.",
    "Your arms become ethereal and gain a reach of 15 feet for the next minute.",
    "You are surrounded by an aura of magical darkness for 1 minute. Creatures with darkvision cannot see through this darkness.",
    "You regain all expended spell slots and sorcery points.",
    "Your body becomes weightless for the next minute, granting you immunity to bludgeoning damage from falling.",
    "You cast Enlarge/Reduce on yourself. If you fail the saving throw, you become Huge for the spell's duration.",
    "Your voice becomes a booming thunderous sound for the next minute. All creatures that can hear you must succeed on a Constitution saving throw DC 15 or become deafened until the end of your next turn.",
    "You are surrounded by floating spectral skulls for 1 minute. Any creature that starts its turn within 5 feet of you takes 2d6 necrotic damage.",
    "Your size decreases by one size category for the next minute.",
    "You gain a flying speed of 60 feet for the next minute.",
    "You can't stop laughing for 1 minute. You fall prone and become incapacitated.",
    "You cast Fog Cloud centered on yourself.",
    "Your eyes emit bright light in a 30-foot radius for the next minute.",
    "You cast Fly on yourself for 1 minute.",
    "Your body becomes incorporeal for the next minute. You can move through other creatures and objects as if they were difficult terrain, but you take 1d10 force damage if you end your turn inside an object.",
    "You cast Fear centered on yourself.",
    "Your size increases by one size category for the next minute.",
    "You regain all expended spell slots.",
    "You cast Polymorph on yourself. If you fail the saving throw, you turn into a sheep for the spell's duration.",
    "You emit a brilliant flash of light in a 30-foot radius for the next minute. Creatures within the area must succeed on a Dexterity saving throw DC 15 or be blinded until the end of their next turn.",
    "You are teleported to a random location within 500 feet of your current location.",
    "You cast Invisibility on yourself for 1 minute.",
    "Your body becomes rubbery and stretch an additional 5 feet for 1 minute.",
    "You are immune to all damage for the next minute.",
    "You cast Slow on yourself.",
    "Your mouth vanishes for the next minute, making it impossible for you to eat or speak.",
    "You regain 2d10 hit points.",
    "You become paralyzed for 1 minute. You can repeat the saving throw at the end of each of your turns, ending the effect on a success.",
    "You cast Fly on a random creature within 60 feet of you.",
    "Your body becomes translucent for 1 minute. You gain resistance to all damage during this time.",
    "You cast Banishment on yourself. You return after 1 minute.",
    "Your skin becomes reflective like a mirror. For the next minute, you have a +2 bonus to AC, and all creatures that start their turn within 10 feet of you must succeed on a Wisdom saving throw DC 15 or become frightened until the end of their turn.",
    "You are surrounded by a faint, ethereal music for 1 minute. Creatures that start their turn within 30 feet of you have disadvantage on concentration checks.",
    "Your hands and feet become invisible for 1 minute. Objects you hold or manipulate are also invisible.",
    "You cast Confusion centered on yourself.",
    "Your size changes by a number of years equal to 1d10. If the roll is odd, you get younger; if it's even, you get older.",
    "You regain all expended sorcery points.",
    "You are wrapped in winding vines for 1 minute. You have advantage on Dexterity (Acrobatics) checks and a climbing speed equal to your walking speed.",
    "Your body becomes ethereal for the next minute. You can move through other creatures and objects as if they were difficult terrain. If you end your turn inside an object, you take 1d10 force damage.",
    "You cast Levitate on yourself.",
    "Your eyes become a solid color for 1 hour. You are blinded during this time.",
    "You cast Reverse Gravity centered on yourself.",
    "Your body becomes covered in shimmering feathers for 1 minute. You have a flying speed of 30 feet and gain advantage on Dexterity (Stealth) checks.",
    "You are frightened of the nearest creature until the end of your next turn.",
    "You cast Web centered on yourself.",
    "Your hands become ethereal for 1 minute. You gain advantage on Dexterity (Sleight of Hand) checks and can pass objects through solid barriers.",
    "You are surrounded by a magical mist for 1 minute. Creatures that start their turn within 10 feet of you have disadvantage on Wisdom (Perception) checks.",
    "Your body becomes transparent for the next minute. You gain resistance to all damage during this time.",
    "You cast Sleep centered on yourself.",
    "You gain immunity to being charmed for the next minute.",
    "Your eyes become pools of darkness for 1 minute. Creatures that start their turn within 30 feet of you have disadvantage on attack rolls against you.",
    "You cast Detect Thoughts on yourself for 1 minute.",
    "Your hair becomes snakes for the next minute. You gain a petrifying gaze attack, and your hair can make unarmed strikes.",
    "You regain all expended spell slots and sorcery points.",
    "You are immune to being intoxicated by alcohol for the next 5d6 days.",
    "You cast Lightning Bolt as a 3rd-level spell in a random direction.",
    "Your body becomes a swirling vortex of air for the next minute. Creatures that start their turn within 10 feet of you must succeed on a Strength saving throw DC 15 or be pushed 10 feet away from you.",
    "You cast Stinking Cloud centered on yourself.",
    "Your voice becomes a whispering echo for the next minute. Creatures that start their turn within 30 feet of you have disadvantage on Wisdom (Perception) checks.",
    "You become invisible for the next minute. During that time, other creatures can't hear you. The invisibility ends if you attack or cast a spell.",
    "If you die within the next minute, you immediately come back to life as if by the Reincarnate spell.",
    "Your size increases by one size category for the next minute.",
    "You are surrounded by flickering flames for 1 minute. Creatures that start their turn within 10 feet of you take 1d10 fire damage.",
    "Your feet become webbed for the next minute, giving you a swimming speed equal to your walking speed.",
    "You cast Mirror Image.",
    "You and all creatures within 30 feet of you gain vulnerability to piercing damage for the next minute.",
    "You regain all expended sorcery points.",
    "You cast Thunderwave as a 3rd-level spell.",
    "Your size decreases by one size category for the next minute.",
    "You are surrounded by a gentle, glowing light for 1 minute. Creatures that start their turn within 10 feet of you gain 1d4 temporary hit points.",
    "Your hands become covered in frost for 1 minute. Your unarmed strikes deal an additional 1d6 cold damage.",
    "You cast Darkness centered on yourself.",
    "Your voice becomes a booming thunderous sound for the next minute. All creatures that can hear you must succeed on a Constitution saving throw DC 15 or become deafened until the end of your next turn.",
    "You and all creatures within 30 feet of you gain vulnerability to slashing damage for the next minute.",
    "You are surrounded by shimmering illusions for 1 minute. Creatures that start their turn within 10 feet of you have disadvantage on Wisdom (Perception) checks.",
    "You can't speak for the next minute. Whenever you try, pink bubbles float out of your mouth.",
    "Your skin becomes hard as stone for the next minute. You have resistance to bludgeoning, piercing, and slashing damage.",
    "You cast Haste on yourself.",
    "You and all creatures within 30 feet of you gain vulnerability to bludgeoning damage for the next minute.",
    "Your body becomes incorporeal for 1 minute. You can move through other creatures and objects as if they were difficult terrain, but you take 1d10 force damage if you end your turn inside an object.",
    "You cast Fear centered on yourself.",
    "You shrink one size category for the next minute.",
    "You regain all expended sorcery points.",
    "You cast Levitate on yourself.",
    "Your eyes emit bright light in a 30-foot radius for the next minute.",
    "You cast Fly on yourself for 1 minute.",
};

const std::string	foodList[] = {
	"Pizza",
	"Burger",
	"Pasta",
	"Sushi",
	"Taco",
	"Ice Cream",
	"Steak",
	"Fried Chicken",
	"Salad",
	"Ramen",
	"Chocolate",
	"Dumplings",
	"Curry",
	"Sandwich",
	"Pancakes",
	"Fries",
	"Cheesecake",
	"Hot Dog",
	"Sashimi",
	"Biryani",
	"Waffles",
	"Nachos",
	"Cupcake",
	"Pho",
	"Muffin",
	"Shawarma",
	"Omelette",
	"Gyoza",
	"Lasagna",
	"Gelato",
	"Doughnut",
	"Spring Roll",
	"Meatballs",
	"Tiramisu",
	"Enchilada",
	"Cannoli",
	"Dim Sum",
	"Chicken Wings",
	"Crepes",
	"Poutine",
	"Churros",
	"Paella",
	"Bagel",
	"Shrimp Scampi",
	"Croissant",
	"Hummus",
	"Baklava",
	"Falafel",
	"Ceviche",
	"Fish and Chips",
	"Coleslaw",
	"Quiche",
	"Gumbo",
	"Potato Salad",
	"Calzone",
	"Beef Stroganoff",
	"Hamburger Steak",
	"Pierogi",
	"Peking Duck",
	"Fish Tacos",
	"Tandoori Chicken",
	"Tuna Salad",
	"Key Lime Pie",
	"Peking Duck",
	"Beef Wellington",
	"Pad Thai",
	"Cajun Jambalaya",
	"Chicken Shawarma",
	"Goulash",
	"Clam Chowder",
	"Beef Bulgogi",
	"Eggplant Parmesan",
	"Lobster Bisque",
	"Chicken Quesadilla",
	"Lamb Kebabs",
	"Shrimp and Grits",
	"Vegetable Stir-Fry",
	"Spinach and Artichoke Dip",
	"Crab Cakes",
	"Chicken Parmesan",
	"Peanut Butter and Jelly Sandwich",
	"Grilled Cheese Sandwich",
	"Tomato Basil Soup",
	"Caprese Salad",
	"Huevos Rancheros",
	"Chicken and Waffles",
	"Hawaiian Pizza",
	"Veggie Burger",
	"Egg Fried Rice",
	"Gazpacho",
	"French Onion Soup",
	"Miso Soup",
	"Tofu Stir-Fry",
	"Veggie Spring Rolls",
	"Ratatouille",
	"Pumpkin Pie",
	"Pecan Pie",
	"Garlic Bread",
	"Mango Sticky Rice",
	"Pistachio Ice Cream",
	"Rocky Road Ice Cream"
};