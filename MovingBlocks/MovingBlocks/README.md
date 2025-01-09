#### Demonstratie van move-semantics
Dit voorbeeld gedraagt zich als een simpel memory-allocation systeempje.
De class `Block` heeft één van de speciale _move_ member functions geïmplementeerd, namelijk de **_move constructor_**.

In de header-file van class `Block` staat een `#define` om de _move_ member functions aan/uit te zetten, zodat je het effect kunt zien: 
als een _move_ constructor aanwezig is, wordt deze (indien mogelijk) automatisch gebruikt.
Anders valt de compiler terug op de **standaard** _copy-constructor_ en _(copy) assignment-operator_.

Maak nu zelf de implementatie van _move-semantics_ compleet door ook de **_move assignment operator_** te implementeren.

**LET OP**: Modere C++ compilers hebben vaak standaard _**Return Value Optimization**_ (of '_**copy elision**_') aan staan:

Dat geeft al een deel van het gedrag van move-semantics voor wat betreft tijdelijke return-waardes
 uit member-functies (maar ook niet in elk geval...).
Het blijft belangrijk om de _**Big Five**_ compleet te implementeren als
je zelf je geheugen managed... zeker als je ook nog gebruik maakt van STL.

Zie: https://stackoverflow.com/questions/18706451/c-return-value-optimization