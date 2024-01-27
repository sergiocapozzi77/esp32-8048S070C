#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <Arduino.h>
#include <vector>

class Ingredients
{
#define ARRAYSIZE 20
    String ingredients[ARRAYSIZE] = {"chicken", "salmon", "beef", "pork", "avocado", "apple cider vinegar", "asparagus", "aubergine", "baby plum tomatoes", "bacon", "baking powder", "balsamic vinegar", "basil", "basil leaves", "basmati rice", "bay leaf", "bay leaves", "beef brisket", "beef fillet", "beef gravy", "beef stock", "bicarbonate of soda", "biryani masala", "black pepper", "black treacle", "borlotti beans", "bowtie pasta", "bramley apples", "brandy", "bread", "breadcrumbs", "broccoli", "brown lentils", "brown rice", "brown sugar", "butter", "cacao", "cajun", "canned tomatoes", "cannellini beans", "cardamom", "carrots", "cashew nuts", "cashews", "caster sugar", "cayenne pepper", "celeriac", "celery", "celery salt", "challots", "charlotte potatoes", "cheddar cheese", "cheese", "cheese curds", "cherry tomatoes", "chestnut mushroom", "chicken breast", "chicken breasts", "chicken legs", "chicken stock", "chicken thighs", "chickpeas", "chili powder", "chilled butter", "chilli", "chilli powder", "chinese broccoli", "chocolate chips", "chopped onion", "chopped parsley", "chopped tomatoes", "chorizo", "christmas pudding", "cilantro", "cinnamon", "cinnamon stick", "cloves", "coco sugar", "cocoa", "coconut cream", "coconut milk", "colby jack cheese", "cold water", "condensed milk", "coriander", "coriander leaves", "coriander seeds", "corn tortillas", "cornstarch", "cream", "creme fraiche", "cubed feta cheese", "cucumber", "cumin", "cumin seeds", "curry powder", "dark brown sugar", "dark soft brown sugar", "dark soy sauce", "demerara sugar", "diced tomatoes", "digestive biscuits", "dill", "doner meat", "double cream", "dried oregano", "dry white wine", "egg plants", "egg rolls", "egg white", "egg yolks", "eggs", "enchilada sauce", "english mustard", "extra virgin olive oil", "fajita seasoning", "farfalle", "fennel bulb", "fennel seeds", "fenugreek", "feta", "fish sauce", "flaked almonds", "flax eggs", "flour", "flour tortilla", "floury potatoes", "" free - range egg "," beaten "", "" free - range eggs "," beaten "", "french lentils", "fresh basil", "fresh thyme", "freshly chopped parsley", "fries", "full fat yogurt", "garam masala", "garlic", "garlic clove", "garlic powder", "garlic sauce", "ghee", "ginger", "ginger cordial", "ginger garlic paste", "ginger paste", "golden syrup", "gouda cheese", "granulated sugar", "grape tomatoes", "greek yogurt", "green beans", "green chilli", "green olives", "green red lentils", "green salsa", "ground almonds", "ground cumin", "ground ginger", "gruyère", "hard taco shells", "harissa spice", "heavy cream", "honey", "horseradish", "hot beef stock", "hotsauce", "ice cream", "italian fennel sausages", "italian seasoning", "jalapeno", "jasmine rice", "jerusalem artichokes", "kale", "khus khus", "king prawns", "kosher salt", "lamb", "lamb loin chops", "lamb mince", "lasagne sheets", "lean minced beef", "leek", "lemon", "lemon juice", "lemon zest", "lemons", "lettuce", "lime", "little gem lettuce", "macaroni", "mackerel", "madras paste", "marjoram", "massaman curry paste", "medjool dates", "meringue nests", "milk", "minced garlic", "miniature marshmallows", "mint", "monterey jack cheese", "mozzarella balls", "muscovado sugar", "mushrooms", "mustard", "mustard powder", "mustard seeds", "nutmeg", "oil", "olive oil", "onion salt", "onions", "orange", "orange zest", "oregano", "oyster sauce", "paprika", "parma ham", "parmesan", "parmesan cheese", "parmigiano-reggiano", "parsley", "peanut butter", "peanut oil", "peanuts", "peas", "pecorino", "penne rigate", "pepper", "pine nuts", "pitted black olives", "plain chocolate", "plain flour", "plum tomatoes", "potato starch", "potatoes", "prawns", "puff pastry", "raspberry jam", "raw king prawns", "red chile flakes", "red chilli", "red chilli powder", "red onions", "red pepper", "red pepper flakes", "red wine", "refried beans", "rice", "rice noodles", "rice stick noodles", "rice vermicelli", "rigatoni", "rocket", "rolled oats", "saffron", "sage", "sake", "salsa", "salt", "salted butter", "sausages", "sea salt", "self-raising flour", "semi-skimmed milk", "sesame seed", "shallots", "shredded mexican cheese", "shredded monterey jack cheese", "small potatoes", "smoked paprika", "smoky paprika", "sour cream", "soy sauce", "soya milk", "spaghetti", "spinach", "spring onions", "squash", "stir-fry vegetables", "strawberries", "sugar", "sultanas", "sunflower oil", "tamarind ball", "tamarind paste", "thai fish sauce", "thai green curry paste", "thai red curry paste", "thyme", "tomato ketchup", "tomato puree", "tomatoes", "toor dal", "tuna", "turmeric", "turmeric powder", "turnips", "vanilla", "vanilla extract", "veal", "vegan butter", "vegetable oil", "vegetable stock", "vegetable stock cube", "vinaigrette dressing", "vine leaves", "vinegar", "water", "white chocolate chips", "white fish", "white fish fillets", "white vinegar", "white wine", "whole milk", "whole wheat", "wholegrain bread", "worcestershire sauce", "yogurt", "zucchini", "pretzels", "cream cheese", "icing sugar", "toffee popcorn", "caramel", "caramel sauce", "tagliatelle", "fettuccine", "clotted cream", "corn flour", "mussels", "fideo", "monkfish", "vermicelli pasta", "baby squid", "squid", "fish stock", "pilchards", "black olives", "onion", "tomato", "duck", "duck legs", "chicken stock cube", "pappardelle pasta", "paccheri pasta", "linguine pasta", "sugar snap peas", "crusty bread", "fromage frais", "clams", "passata", "rapeseed oil", "stilton cheese", "lamb leg", "lamb shoulder", "apricot", "butternut squash", "couscous", "minced beef", "turkey mince", "barbeque sauce", "sweetcorn", "goose fat", "duck fat", "fennel", "red wine vinegar", "haricot beans", "rosemary", "butter beans", "pinto beans", "tomato sauce", "mascarpone", "mozzarella", "ricotta", "dried apricots", "capers", "banana", "raspberries", "blueberries", "walnuts", "pecan nuts", "maple syrup", "light brown soft sugar", "dark brown soft sugar", "dark chocolate chips", "milk chocolate", "dark chocolate", "pumpkin", "shortcrust pastry", "peanut cookies", "gelatine leafs", "peanut brittle", "peaches", "yellow pepper", "green pepper", "courgettes", "tinned tomatos", "chestnuts", "wild mushrooms", "truffle oil", "paneer", "naan bread", "lentils", "roasted vegetables", "kidney beans", "mixed grain", "tahini", "tortillas", "udon noodles", "cabbage", "shiitake mushrooms", "mirin", "sesame seed oil", "baguette", "vine tomatoes", "suet", "swede", "ham", "oysters", "stout", "lard", "lamb kidney", "beef kidney", "haddock", "smoked haddock", "brussels sprouts", "raisins", "currants", "custard", "mixed peel", "redcurrants", "blackberries", "hazlenuts", "braeburn apples", "red food colouring", "pink food colouring", "blue food colouring", "yellow food colouring", "apricot jam", "marzipan", "almonds", "black pudding", "baked beans", "white flour", "yeast", "fruit mix", "dried fruit", "cherry", "glace cherry", "treacle", "oatmeal", "oats", "egg", "beef shin", "bouquet garni", "single cream", "red wine jelly", "apples", "goats cheese", "prosciutto", "unsalted butter", "brie", "tarragon leaves", "chives", "pears", "white chocolate", "star anise", "tiger prawns", "custard powder", "desiccated coconut", "frozen peas", "minced pork", "creamed corn", "sun-dried tomatoes", "dijon mustard", "tabasco sauce", "canola oil", "cod", "salt cod", "ackee", "jerk", "ground beef", "baby aubergine", "paella rice", "scotch bonnet", "oxtail", "broad beans", "red snapper", "malt vinegar", "rice vinegar", "water chestnut", "tofu", "doubanjiang", "fermented black beans", "scallions", "sichuan pepper", "wonton skin", "starch", "rice wine", "cooking wine", "duck sauce", "gochujang", "bean sprouts", "noodles", "wood ear mushrooms", "dark rum", "light rum", "rum", "english muffins", "muffins", "white wine vinegar", "smoked salmon", "mars bar", "rice krispies", "ancho chillies", "almond milk", "allspice", "almond extract", "tripe", "goat meat", "black beans", "anchovy fillet", "ras el hanout", "filo pastry", "orange blossom water", "candied peel", "grand marnier", "sherry", "rose water", "mixed spice", "mincemeat", "sweet potatoes", "bread rolls", "bun", "potatoe buns", "ground pork", "pork chops", "yukon gold potatoes", "yellow onion", "beef stock concentrate", "chicken stock concentrate", "persian cucumber", "mayonnaise", "sriracha", "rhubarb", "pita bread", "bulgur wheat", "quinoa", "dill pickles", "sesame seed burger buns", "buns", "iceberg lettuce", "gherkin relish", "cheese slices", "shortening", "warm water", "boiling water", "pickle juice", "powdered sugar", "kielbasa", "polish sausage", "sauerkraut", "caraway seed", "herring", "jam", "mulukhiyah", "sushi rice", "figs", "cider", "beetroot", "sardines", "ciabatta", "buckwheat", "prunes"};

public:
    Ingredients();
    std::vector<String> GetIngredientsStartingWith(const char *text);
};

extern Ingredients ingredients;

#endif