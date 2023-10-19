import { Component } from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {
  expression: string = '0';
  value1!: number;
  value2!: number;
  operation!: number;

  constructor() {}

  showValue(value: string) {
    if (this.expression.length && this.expression == '0') {
      this.expression = value;
    } else {
      this.expression += value;
    }
  }

  addOperation(valor: number) {
    this.operation = valor;
    this.value1 = +this.expression;
    this.value1 = Number(this.expression);
    this.zero();
  }

  zero() {
    this.expression = '0';
  }

  evaluate() {
    this.value2 = +this.expression;
    switch (this.operation) {
      case 0:
        this.expression = "" + (this.value1 + this.value2);
        break;
      case 1:
        this.expression = "" + (this.value1 - this.value2);
        break;
      case 2:
        this.expression = "" + (this.value1 * this.value2);
        break;
      case 3:
        this.expression = "" + (this.value1 / this.value2);
        break;
    }
  }
}
