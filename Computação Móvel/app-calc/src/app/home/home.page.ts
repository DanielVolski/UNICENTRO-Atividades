import { Component } from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {
  display: string = '0';
  expression: string = '';

  displayButtonContent(value: string) {
    if (this.display == '0')
      this.display = value;
    else {
      if (!(value == '.' && this.display.includes('.')))
        this.display += value;
    }
  }

  clearDisplay() {
    this.display = '0';
  }

  clearExpression() {
    this.expression = '';
  }

  handleOperation(op: string) {
    console.log(this.expression);
    this.expression += this.display;
    this.expression = this.expression + op;
    this.clearDisplay();
  }

  negate() {
    if (this.display != '0')
      this.display = String(-Number(this.display));
  }

  percentage() {
    this.display = String(Number(this.display) / 100)
  }

  evaluate() {
    let stack: string[] = [];
    let outputQueue: string[] = [];
    let expression = this.expression + this.display;

    for (let token of expression.split(/([+\-*/])/)) {
      token = token.trim();

      if (!token) continue;

      if (!isNaN(Number(token))) {
        outputQueue.push(token);
      } else if (this.isOperator(token)) {
        while (
          stack.length > 0 &&
          this.isOperator(stack[stack.length - 1]) &&
          this.getPrecedence(token) <= this.getPrecedence(stack[stack.length - 1])
        ) {
          outputQueue.push(stack.pop()!);
        }
        stack.push(token);
      }
    }

    while (stack.length > 0)
      outputQueue.push(stack.pop()!);

    stack = [];
    for (let token of outputQueue) {
      if (!this.isOperator(token)) {
        stack.push(token);
      } else {
        let b = parseFloat(stack.pop()!);
        let a = parseFloat(stack.pop()!);
        let result = this.performOperation(a, b, token);
        stack.push(result.toString());
      }
    }

    if (stack.length === 1) {
      this.display = stack[0];
    } else {
      this.display = 'Invalid Expression';
    }

    this.clearExpression();
  }

  private isOperator(token: string): boolean {
    return /^[+\-*/]$/.test(token);
  }

  private getPrecedence(operator: string): number {
    return (operator == '*' || operator == '/' ? 2 : 1);
  }

  private performOperation(a: number, b: number, operator: string): number {
    switch (operator) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return (b == 0 ? NaN : a / b);
      default:
        return NaN;
    }
  }
}
