var ARRAY_SIZE = 50;
var ELEM_LIMIT = 10;
var TIME_DELAY = 0.005;
function initArrayValues() {
    return Array.apply(null, Array(ARRAY_SIZE)).map(function () {
        return Math.round(Math.random() * ELEM_LIMIT);
    });
}
function sleep(ms) {
    return new Promise(function (resolve) { return setTimeout(resolve, ms); });
}
function barGraph(array) {
    var maxElement = Math.max.apply(Math, array);
    for (var i = 0; i < maxElement; i++) {
        for (var j = 0; j < array.length; j++) {
            if (array[j] >= maxElement - i) {
                process.stdout.write("*");
            }
            else {
                process.stdout.write(" ");
            }
        }
        console.log();
    }
}
function isSorted(array) {
    for (var i = 0; i < array.length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
function bubbleSort(array) {
    var _a;
    barGraph(array);
    for (var i = 0; i < array.length - 1; i++) {
        for (var j = 0; j < array.length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                _a = [array[j + 1], array[j]], array[j] = _a[0], array[j + 1] = _a[1];
                sleep(TIME_DELAY);
                console.clear();
                barGraph(array);
            }
        }
    }
    return array;
}
function main() {
    var array = initArrayValues();
    array = bubbleSort(array);
    while (true) {
        if (isSorted(array)) {
            console.log("DONE");
            break;
        }
        else {
            array = bubbleSort(array);
        }
    }
    console.table(array);
    barGraph(array);
}
main();
