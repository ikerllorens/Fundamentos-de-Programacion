/**
 * <file>ejemplo_xml_doc.c</file>
 * <brief>Ejemplo de documentación usando formato XML de Doxygen</brief>
 * <author>Iker Llorens</author>
 * 
 * Este archivo demuestra cómo se pueden usar las etiquetas XML
 * en lugar del formato @ para documentar código en Doxygen.
 * Ambos formatos son equivalentes y generan la misma salida.
 */

/**
 * <brief>Multiplica dos números enteros</brief>
 * 
 * Esta función demuestra el uso de etiquetas XML en la documentación.
 * 
 * <param name="a">Primer número a multiplicar</param>
 * <param name="b">Segundo número a multiplicar</param>
 * <return>El producto de a * b</return>
 */
int multiplicar(int a, int b)
{
    return a * b;
}
