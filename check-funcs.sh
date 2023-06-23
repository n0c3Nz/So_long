#!/bin/bash

archivos_c=$(find . -maxdepth 1 -type f -name "*.c")

for archivo in $archivos_c; do
  echo "📁 $archivo"
  funciones_encontradas=$(grep -E "^(int|float|char|double|void)[[:space:]]+.*" "$archivo")

  if [ -z "$funciones_encontradas" ]; then
    echo "❌ Empty"
  else
    echo "$funciones_encontradas" | while IFS= read -r linea; do
      echo "🔎 Función:  $linea"
    done
  fi

  echo
done
