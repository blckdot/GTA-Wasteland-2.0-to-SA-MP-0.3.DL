GetBoneName(boneid, name[], name_size) {
    switch( boneid ) {
        case 1:
            strunpack(name, !"Спина", name_size);
        case 2:
            strunpack(name, !"Голова", name_size);
        case 3:
            strunpack(name, !"Левое плечо", name_size);
        case 4:
            strunpack(name, !"Правое плечо", name_size);
        case 5:
            strunpack(name, !"Левая рука", name_size);
        case 6:
            strunpack(name, !"Правая рука", name_size);
        case 7:
            strunpack(name, !"Левое бедро", name_size);
        case 8:
            strunpack(name, !"Правое бедро", name_size);
        case 9:
            strunpack(name, !"Левая нога", name_size);
        case 10:
            strunpack(name, !"Правая нога", name_size);
        case 11:
            strunpack(name, !"Правое колено", name_size);
        case 12:
            strunpack(name, !"Левое колено", name_size);
        case 13:
            strunpack(name, !"Левое предплечье", name_size);
        case 14:
            strunpack(name, !"Правое предплечье", name_size);
        case 15:
            strunpack(name, !"Левая ключица", name_size);
        case 16:
            strunpack(name, !"Правая ключица", name_size);
        case 17:
            strunpack(name, !"Шея", name_size);
        case 18:
            strunpack(name, !"Челюсть", name_size);
        default: {
            format(name, name_size, "Неверная часть тела (%i)", boneid);
            return 0;
        }
    }
    return 1;
}
